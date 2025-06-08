
// MFCApplicationDoc.h : interface of the CMFCApplicationDoc class
//


#pragma once
#include "Circle.h"
#include "EditCircleDlg.h"


class CMFCApplicationDoc : public CDocument
{
protected: // create from serialization only
	CMFCApplicationDoc() noexcept;
	DECLARE_DYNCREATE(CMFCApplicationDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	CCircle GetCircle() { return circle; }
	void SetCircle(CCircle& newCircle) {
		circle.SetCenterX(newCircle.GetCenterX());
		circle.SetCenterY(newCircle.GetCenterY());
		circle.SetRadius(newCircle.GetRadius());
	}
	virtual ~CMFCApplicationDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnCircleEdit();

private:
	CCircle circle;
	
};
