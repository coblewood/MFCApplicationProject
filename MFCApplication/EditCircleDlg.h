#pragma once
#include "afxdialogex.h"


// EditCircleDlg dialog

class EditCircleDlg : public CDialog
{
	DECLARE_DYNAMIC(EditCircleDlg)

public:
	EditCircleDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~EditCircleDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDIT_CIRCLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int c_radius;
	int c_center_x;
	int c_center_y;
};
