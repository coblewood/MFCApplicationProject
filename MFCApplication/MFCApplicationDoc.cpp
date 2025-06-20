
// MFCApplicationDoc.cpp : implementation of the CMFCApplicationDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication.h"
#endif

#include "MFCApplicationDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplicationDoc

IMPLEMENT_DYNCREATE(CMFCApplicationDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplicationDoc, CDocument)
	ON_COMMAND(ID_CIRCLE_EDIT, &CMFCApplicationDoc::OnCircleEdit)
END_MESSAGE_MAP()


// CMFCApplicationDoc construction/destruction

CMFCApplicationDoc::CMFCApplicationDoc() noexcept
{
	// TODO: add one-time construction code here

}

CMFCApplicationDoc::~CMFCApplicationDoc()
{
}

BOOL CMFCApplicationDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	circle.SetCenterX(0);
	circle.SetCenterX(0);
	circle.SetRadius(0);
	UpdateAllViews(NULL);

	return TRUE;
}

BOOL CMFCApplicationDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	UpdateAllViews(NULL);

	return TRUE;
}

// CMFCApplicationDoc serialization

void CMFCApplicationDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << circle.GetCenterX();
		ar << circle.GetCenterY();
		ar << circle.GetRadius();
	}
	else
	{
		int x, y, r;
		ar >> x;
		ar >> y;
		ar >> r;

		circle.SetCenterX(x);
		circle.SetCenterY(y);
		circle.SetRadius(r);
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCApplicationDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCApplicationDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCApplicationDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCApplicationDoc diagnostics

#ifdef _DEBUG
void CMFCApplicationDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplicationDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCApplicationDoc commands

void CMFCApplicationDoc::OnCircleEdit()
{
	// TODO: Add your command handler code here
	EditCircleDlg editCircleDlgBox;
	editCircleDlgBox.c_radius = circle.GetRadius();
	editCircleDlgBox.c_center_x = circle.GetCenterX();
	editCircleDlgBox.c_center_y = circle.GetCenterY();

	if (editCircleDlgBox.DoModal() == IDOK) {
		circle.SetRadius(editCircleDlgBox.c_radius);
		circle.SetCenterX(editCircleDlgBox.c_center_x);
		circle.SetCenterY(editCircleDlgBox.c_center_y);
		UpdateAllViews(NULL);
	}
}
