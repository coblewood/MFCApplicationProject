// EditCircleDlg.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication.h"
#include "afxdialogex.h"
#include "EditCircleDlg.h"


// EditCircleDlg dialog

IMPLEMENT_DYNAMIC(EditCircleDlg, CDialog)

EditCircleDlg::EditCircleDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_EDIT_CIRCLE, pParent)
	, c_radius(0)
	, c_center_x(0)
	, c_center_y(0)
{

}

EditCircleDlg::~EditCircleDlg()
{
}

void EditCircleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RADIUS, c_radius);
	DDX_Text(pDX, IDC_EDIT_CENTERX, c_center_x);
	DDX_Text(pDX, IDC_EDIT_CENTERY, c_center_y);
}


BEGIN_MESSAGE_MAP(EditCircleDlg, CDialog)
END_MESSAGE_MAP()


// EditCircleDlg message handlers
