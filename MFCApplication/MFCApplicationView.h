
// MFCApplicationView.h : interface of the CMFCApplicationView class
//

#pragma once


class CMFCApplicationView : public CView
{
protected: // create from serialization only
	CMFCApplicationView() noexcept;
	DECLARE_DYNCREATE(CMFCApplicationView)

// Attributes
public:
	CMFCApplicationDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCApplicationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCircleNew();

private:
	bool drawCircle {false};
};

#ifndef _DEBUG  // debug version in MFCApplicationView.cpp
inline CMFCApplicationDoc* CMFCApplicationView::GetDocument() const
   { return reinterpret_cast<CMFCApplicationDoc*>(m_pDocument); }
#endif

