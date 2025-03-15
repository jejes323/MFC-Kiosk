
// MFC_KIOSKDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_KIOSK.h"
#include "MFC_KIOSKDlg.h"
#include "afxdialogex.h"
#include "Modal_Pay.h"
#include "flag.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CMFCKIOSKDlg 대화 상자

CMFCKIOSKDlg::CMFCKIOSKDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_KIOSK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCKIOSKDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT1, m_Text1);
	DDX_Control(pDX, IDC_TEXT2, m_Text2);
	DDX_Control(pDX, IDC_TEXT3, m_Text3);
	DDX_Control(pDX, IDC_TEXT4, m_Text4);
	DDX_Control(pDX, IDC_TEXT5, m_Text5);
	DDX_Control(pDX, IDC_TEXT6, m_Text6);
	DDX_Control(pDX, IDC_TEXT7, m_Text7);
	DDX_Control(pDX, IDC_TEXT8, m_Text8);
	DDX_Control(pDX, IDC_TEXT9, m_Text9);
	DDX_Control(pDX, IDC_PRICE1, m_Price1);
	DDX_Control(pDX, IDC_PRICE2, m_Price2);
	DDX_Control(pDX, IDC_PRICE3, m_Price3);
	DDX_Control(pDX, IDC_PRICE4, m_Price4);
	DDX_Control(pDX, IDC_PRICE5, m_Price5);
	DDX_Control(pDX, IDC_PRICE6, m_Price6);
	DDX_Control(pDX, IDC_PRICE7, m_Price7);
	DDX_Control(pDX, IDC_PRICE8, m_Price8);
	DDX_Control(pDX, IDC_PRICE9, m_Price9);
	DDX_Control(pDX, IDC_PICTUREBOX1, m_pictureControl1);
	DDX_Control(pDX, IDC_PICTUREBOX2, m_pictureControl2);
	DDX_Control(pDX, IDC_PICTUREBOX3, m_pictureControl3);
	DDX_Control(pDX, IDC_PICTUREBOX4, m_pictureControl4);
	DDX_Control(pDX, IDC_PICTUREBOX5, m_pictureControl5);
	DDX_Control(pDX, IDC_PICTUREBOX6, m_pictureControl6);
	DDX_Control(pDX, IDC_PICTUREBOX7, m_pictureControl7);
	DDX_Control(pDX, IDC_PICTUREBOX8, m_pictureControl8);
	DDX_Control(pDX, IDC_PICTUREBOX9, m_pictureControl9);
	DDX_Control(pDX, IDC_TEXT_ORDER1, m_textOrder1);
	DDX_Control(pDX, IDC_TEXT_ORDER1_SUM, m_textOrderSum1);
	DDX_Control(pDX, IDC_TEXT_ORDER2_SUM, m_textOrderSum2);
	DDX_Control(pDX, IDC_TEXT_ORDER3_SUM, m_textOrderSum3);
	DDX_Control(pDX, IDC_TEXT_ORDER4_SUM, m_textOrderSum4);
	DDX_Control(pDX, IDC_TEXT_ORDER5_SUM, m_textOrderSum5);
	DDX_Control(pDX, IDC_TEXT_ORDER6_SUM, m_textOrderSum6);
	DDX_Control(pDX, IDC_TEXT_ORDER7_SUM, m_textOrderSum7);
	DDX_Control(pDX, IDC_TEXT_ORDER8_SUM, m_textOrderSum8);

	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT4, m_edit4);
	DDX_Control(pDX, IDC_EDIT5, m_edit5);
	DDX_Control(pDX, IDC_EDIT6, m_edit6);
	DDX_Control(pDX, IDC_EDIT7, m_edit7);
	DDX_Control(pDX, IDC_EDIT8, m_edit8);

	DDX_Control(pDX, 1064, m_orderlist_1); //IDC_TEXT_ORDER 첫번째 ( 주문 리스트 첫번째 )
	DDX_Control(pDX, IDC_TEXT_ORDER12, m_orderlist_2);
	DDX_Control(pDX, IDC_TEXT_ORDER13, m_orderlist_3);
	DDX_Control(pDX, 1044, m_orderlist14_2);
	DDX_Control(pDX, IDC_TEXT_ORDER15, m_orderlist_5);
	DDX_Control(pDX, IDC_TEXT_ORDER16, m_orderlist_6);
	DDX_Control(pDX, IDC_TEXT_ORDER17, m_orderlist_7);
	DDX_Control(pDX, IDC_TEXT_ORDER18, m_orderlist_8);

	DDX_Control(pDX, IDC_TEXT_ALLSUM, m_ALLSUM);
}

BEGIN_MESSAGE_MAP(CMFCKIOSKDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON_COFFEE, &CMFCKIOSKDlg::OnClickedButtonCoffee)
	ON_BN_CLICKED(IDC_BUTTON_CRAFT, &CMFCKIOSKDlg::OnClickedButtonCraft)
	ON_BN_CLICKED(IDC_BUTTON_TEA, &CMFCKIOSKDlg::OnClickedButtonTea)
	ON_BN_CLICKED(IDC_BUTTON_BREAD, &CMFCKIOSKDlg::OnClickedButtonBread)
	ON_BN_CLICKED(IDC_BUTTON_UP, &CMFCKIOSKDlg::OnClickedButtonUp)
	ON_BN_CLICKED(IDC_BUTTON_DOWN, &CMFCKIOSKDlg::OnClickedButtonDown)
	ON_BN_CLICKED(IDC_BUTTON_KOREAN, &CMFCKIOSKDlg::OnClickedButtonKorean)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_HERE, &CMFCKIOSKDlg::OnClickedButtonHere)
	ON_BN_CLICKED(IDC_BUTTON_TOGO, &CMFCKIOSKDlg::OnClickedButtonTogo)

	ON_STN_CLICKED(IDC_TEXT_ORDER13, &CMFCKIOSKDlg::OnStnClickedTextOrder13)
	ON_STN_CLICKED(IDC_TEXT_ORDER3_SUM, &CMFCKIOSKDlg::OnStnClickedTextOrder3Sum)
	ON_WM_LBUTTONDOWN()
	ON_STN_CLICKED(IDC_TEXT_ORDER18, &CMFCKIOSKDlg::OnStnClickedTextOrder18)
	ON_STN_CLICKED(IDC_TEXT_ORDER12, &CMFCKIOSKDlg::OnStnClickedTextOrder12)
	ON_STN_CLICKED(IDC_TEXT_ORDER19, &CMFCKIOSKDlg::OnStnClickedTextOrder19)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCKIOSKDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_CANC1, &CMFCKIOSKDlg::OnBnClickedCanc1)
	ON_BN_CLICKED(IDC_CANC2, &CMFCKIOSKDlg::OnBnClickedCanc2)
	ON_BN_CLICKED(IDC_CANC3, &CMFCKIOSKDlg::OnBnClickedCanc3)
	ON_BN_CLICKED(IDC_CANC4, &CMFCKIOSKDlg::OnBnClickedCanc4)
	ON_BN_CLICKED(IDC_CANC5, &CMFCKIOSKDlg::OnBnClickedCanc5)
	ON_BN_CLICKED(IDC_CANC6, &CMFCKIOSKDlg::OnBnClickedCanc6)
	ON_BN_CLICKED(IDC_CANC7, &CMFCKIOSKDlg::OnBnClickedCanc7)
	ON_BN_CLICKED(IDC_CANC8, &CMFCKIOSKDlg::OnBnClickedCanc8)
	ON_STN_CLICKED(IDC_TEXT_ORDER2_SUM, &CMFCKIOSKDlg::OnStnClickedTextOrder2Sum)
	ON_STN_CLICKED(IDC_TEXT_ORDER8_SUM, &CMFCKIOSKDlg::OnStnClickedTextOrder8Sum)
	ON_STN_CLICKED(IDC_letf1, &CMFCKIOSKDlg::OnStnClickedletf1)
	ON_STN_CLICKED(IDC_letf2, &CMFCKIOSKDlg::OnStnClickedletf2)
	ON_STN_CLICKED(IDC_letf3, &CMFCKIOSKDlg::OnStnClickedletf3)
	ON_STN_CLICKED(IDC_letf4, &CMFCKIOSKDlg::OnStnClickedletf4)
	ON_STN_CLICKED(IDC_letf5, &CMFCKIOSKDlg::OnStnClickedletf5)
	ON_STN_CLICKED(IDC_letf6, &CMFCKIOSKDlg::OnStnClickedletf6)
	ON_STN_CLICKED(IDC_letf7, &CMFCKIOSKDlg::OnStnClickedletf7)
	ON_STN_CLICKED(IDC_letf8, &CMFCKIOSKDlg::OnStnClickedletf8)
	ON_STN_CLICKED(IDC_right1, &CMFCKIOSKDlg::OnStnClickedright1)
	ON_STN_CLICKED(IDC_right2, &CMFCKIOSKDlg::OnStnClickedright2)
	ON_STN_CLICKED(IDC_right3, &CMFCKIOSKDlg::OnStnClickedright3)
	ON_STN_CLICKED(IDC_right4, &CMFCKIOSKDlg::OnStnClickedright4)
	ON_STN_CLICKED(IDC_right5, &CMFCKIOSKDlg::OnStnClickedright5)
	ON_STN_CLICKED(IDC_right6, &CMFCKIOSKDlg::OnStnClickedright6)
	ON_STN_CLICKED(IDC_right7, &CMFCKIOSKDlg::OnStnClickedright7)
	ON_STN_CLICKED(IDC_right8, &CMFCKIOSKDlg::OnStnClickedright8)
	ON_STN_CLICKED(IDC_PICTUREBOX1, &CMFCKIOSKDlg::OnStnClickedPicturebox1)
END_MESSAGE_MAP()


// CMFCKIOSKDlg 메시지 처리기
BOOL CMFCKIOSKDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	LONG style = GetWindowLong(this->m_hWnd, GWL_STYLE);
	style &= ~(WS_MAXIMIZEBOX); // 최대화 버튼 제거
	SetWindowLong(this->m_hWnd, GWL_STYLE, style);

	// 다이얼로그 크기 고정
	SetWindowPos(NULL, 0, 0, 1920, 1080, SWP_NOMOVE | SWP_NOZORDER); // 해상도 1920 1080 고정
	//배경 이미지 로드
	SetBackgroundImage(134); // 배경 이미지 불러오기 

	/**************1920 1080 해상도에 맞춰서 동적으로 버튼 위치이동 로직입니다. *****************************************/

					/**		모든 버튼 하나하나 위치를 지정해주지 않으면 
							리소스 뷰에서 버튼을 건들이면 
					바로 버튼 위치가 바뀌어서 일일이 지정해줌ㅠㅠ.		**/
	
	/*1920 1080 해상도 기준입니다.*/	
	//버튼에 대한 동적 이동 로직입니다.
	m_setButtonPositiion(68, 83, IDC_BUTTON_COFFEE); //커피 버튼
	m_setButtonPositiion(321, 83, 1001); //제조음료 버튼
	m_setButtonPositiion(578, 83, 1002); // 티 버튼 
	m_setButtonPositiion(835, 83, 1003); // 제과류 버튼
	m_setButtonPositiion(1248, 803 , 1005); // 매장이용 버튼 
	m_setButtonPositiion(1569, 803, 1006); // 포장 버튼

	m_setButtonPositiion(108, 170, 1007); //매뉴 이미지 박스1
	m_setButtonPositiion(468, 170, 1008); // 2
	m_setButtonPositiion(808, 170, 1009);
	m_setButtonPositiion(108, 450, 1010);
	m_setButtonPositiion(468, 450, 1011);
	m_setButtonPositiion(808, 450, 1012);
	m_setButtonPositiion(108, 750, 1013);
	m_setButtonPositiion(468, 750, 1014);
	m_setButtonPositiion(808, 750, 1015); //9

	m_setButtonPositiion(129, 370, 1016); //매뉴 이름 텍스트 1
	m_setButtonPositiion(479, 370, 1017); // 2
	m_setButtonPositiion(829, 370, 1018);
	
	m_setButtonPositiion(129, 650, 1019);
	m_setButtonPositiion(479, 650, 1020);
	m_setButtonPositiion(829, 650, 1021);

	m_setButtonPositiion(129, 950, 1022);
	m_setButtonPositiion(479, 950, 1023);
	m_setButtonPositiion(829, 950, 1024); // 9

	m_setButtonPositiion(129, 410, 1025); //매뉴 가격 텍스트 1
	m_setButtonPositiion(479, 410, 1034); // 2
	m_setButtonPositiion(829, 410, 1035);

	m_setButtonPositiion(129, 690, 1036);
	m_setButtonPositiion(479, 690, 1037);
	m_setButtonPositiion(829, 690, 1038);

	m_setButtonPositiion(129, 990, 1039);
	m_setButtonPositiion(479, 990, 1040);
	m_setButtonPositiion(829, 990, 1041); 

	m_setButtonPositiion(1155, 410, 1026);
	m_setButtonPositiion(1155, 925 , 1027);

	//주문 텍스트에 대한 동적 이동 로직입니다.
	m_setButtonPositiion(1242, 130, 1064);
	m_setButtonPositiion(1242, 190, 1047);
	m_setButtonPositiion(1242, 260, 1043);
	m_setButtonPositiion(1242, 330, 1044);
	m_setButtonPositiion(1242, 400, 1045);
	m_setButtonPositiion(1242, 470, 1046);
	m_setButtonPositiion(1242, 540, 1048);
	m_setButtonPositiion(1242, 610, 1049);
	
	//주문 가격 총합 텍스트에 대한 동적 이동 로직입니다.
	m_setButtonPositiion(1600, 130, 1029);
	m_setButtonPositiion(1600, 190, 1030);
	m_setButtonPositiion(1600, 260, 1031);
	m_setButtonPositiion(1600, 330, 1032);
	m_setButtonPositiion(1600, 400, 1033);
	m_setButtonPositiion(1600, 470, 1042);
	m_setButtonPositiion(1600, 540, 1050);
	m_setButtonPositiion(1600, 610, 1051);
	//주문 수량 에디트박스에 대한 동적 이동 로직입니다. 
	m_setButtonPositiion(1682, 130, 1052);
	m_setButtonPositiion(1682, 190, 1053);
	m_setButtonPositiion(1682, 260, 1054);
	m_setButtonPositiion(1682, 330, 1055);
	m_setButtonPositiion(1682, 400, 1056);
	m_setButtonPositiion(1682, 470, 1057);
	m_setButtonPositiion(1682, 540, 1058);
	m_setButtonPositiion(1682, 610, 1059);
	//주문 수량 조절 버튼에 대한 동적 이동 로직입니다.
	m_setButtonPositiion(1552, 140, 1074);
	m_setButtonPositiion(1552, 200, 1081);
	m_setButtonPositiion(1552, 270, 1082);
	m_setButtonPositiion(1552, 340, 1083);
	m_setButtonPositiion(1552, 410, 1085);
	m_setButtonPositiion(1552, 480, 1086);
	m_setButtonPositiion(1552, 550, 1087);
	m_setButtonPositiion(1552, 620, 1088);

	m_setButtonPositiion(1635, 140, 1075);
	m_setButtonPositiion(1635, 200, 1089);
	m_setButtonPositiion(1635, 270, 1090);
	m_setButtonPositiion(1635, 340, 1091);
	m_setButtonPositiion(1635, 410, 1092);
	m_setButtonPositiion(1635, 480, 1093);
	m_setButtonPositiion(1635, 550, 1094);
	m_setButtonPositiion(1635, 620, 1096);

	//주문 취소 버튼에 대한 동적 이동 로직
	m_setButtonPositiion(1245, 130, IDC_CANC1);
	m_setButtonPositiion(1245, 190, IDC_CANC2);
	m_setButtonPositiion(1245, 260, IDC_CANC3);
	m_setButtonPositiion(1245, 330, IDC_CANC4);
	m_setButtonPositiion(1245, 400, IDC_CANC5);
	m_setButtonPositiion(1245, 470, IDC_CANC6);
	m_setButtonPositiion(1245, 540, IDC_CANC7);
	m_setButtonPositiion(1245, 610, IDC_CANC8);

	//모든 주문 전체 가격 총합 텍스트 이동 로직입니다.
	m_setButtonPositiion(1540, 730, 1060);
	//언어에 대한 동적 이동 로직입니다.
	m_setButtonPositiion(1570, 20, IDC_BUTTON_KOREAN);

	m_setFont_menu(31, FW_BOLD); 
	m_setFont_price(31, FW_THIN);
	m_setFont_editbox(31, FW_HEAVY);
	m_setFont_order(31, FW_BOLD);
	m_setFont_ordersum(31, FW_BOLD);
	m_setFont_allsum(55, FW_BOLD);
	
	m_buttonCoffee = m_buttonBread = m_buttonTea = m_buttonCraft = false;
	m_buttonCoffeeDown = m_buttonBreadDown = m_buttonTeaDown = m_buttonCraftDown = false;
	m_korean = m_english = m_chinese = false;

	OnClickedButtonKorean();   //초기화면 한국어
	OnClickedButtonCoffee();     //초기화면 커피메뉴

	showSoldOut();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCKIOSKDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

void CMFCKIOSKDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCKIOSKDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCKIOSKDlg::m_setButtonPositiion(int buttonX, int buttonY, int nID)
{
	// TODO: 여기에 구현 코드 추가.
		/**************해상도에 맞춰서 동적으로 버튼 위치이동 로직입니다. *****************************************/
	// 현재 화면 해상도 얻기
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// 버튼 위치 계산 (예: 화면의 가운데에 배치)


	
	// 버튼 위치 설정
	CWnd* pButton = GetDlgItem(nID); // IDC_MYBUTTON은 버튼의 ID
	if (pButton != nullptr)
	{
		pButton->SetWindowPos(NULL, buttonX, buttonY, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	}

	/****************************************************************************************************/
}

void CMFCKIOSKDlg::m_setFont_for_m_font_menu(int nID)
{
	// TODO: 여기에 구현 코드 추가.
	// 글꼴 적용
	CEdit* pEdit = (CEdit*)GetDlgItem(nID); 
	if (pEdit != nullptr)
	{
		//pEdit->SetFont(&m_font);

		pEdit->SetFont(&m_font_menu);
		
	}
}

void CMFCKIOSKDlg::m_setFont_for_m_font_price(int nID)
{
	//매뉴 가격 텍스트 폰트를 변경하기 위한 멤버함수
	CEdit* pEdit = (CEdit*)GetDlgItem(nID);
	if (pEdit != nullptr)
	{
		//pEdit->SetFont(&m_font);

		pEdit->SetFont(&m_font_price);
	}
}
void CMFCKIOSKDlg::m_setFont_for_m_font_edit(int nID)
{
	//매뉴 가격 텍스트 폰트를 변경하기 위한 멤버함수
	CEdit* pEdit = (CEdit*)GetDlgItem(nID);
	if (pEdit != nullptr)
	{
		//pEdit->SetFont(&m_font);

		pEdit->SetFont(&m_font_editbox);

	}
}
void CMFCKIOSKDlg::m_setFont_for_m_font_order(int nID)
{
	//매뉴 가격 텍스트 폰트를 변경하기 위한 멤버함수
	CEdit* pEdit = (CEdit*)GetDlgItem(nID);
	if (pEdit != nullptr)
	{
		//pEdit->SetFont(&m_font);

		pEdit->SetFont(&m_font_order);

	}
}
void CMFCKIOSKDlg::m_setFont_order_amount(int nID)
{
	// TODO: 여기에 구현 코드 추가.
	// 글꼴 적용
	CEdit* pEdit = (CEdit*)GetDlgItem(nID);
	if (pEdit != nullptr)
	{
		//pEdit->SetFont(&m_font);

		pEdit->SetFont(&m_font_order_amount);
	}
}

void CMFCKIOSKDlg::m_setFont_for_m_font_ordersum(int nID)
{
	//매뉴 가격 텍스트 폰트를 변경하기 위한 멤버함수
	CEdit* pEdit = (CEdit*)GetDlgItem(nID);
	if (pEdit != nullptr)
	{
		//pEdit->SetFont(&m_font);

		pEdit->SetFont(&m_font_ordersum);
	}
}
void CMFCKIOSKDlg::m_setFont_for_m_font_allsum(int nID)
{
	//메뉴 가격 텍스트 폰트를 변경하기 위한 멤버함수
	CEdit* pEdit = (CEdit*)GetDlgItem(nID);
	if (pEdit != nullptr)
	{
		//pEdit->SetFont(&m_font);

		pEdit->SetFont(&m_font_allsum);

	}
}

void CMFCKIOSKDlg::m_setFont_menu(int fontsize, int FW)
{
	m_font_menu.CreateFont(
		fontsize,                        // 높이
		0,                         // 폭
		0,                         // 기울기 각도
		0,                         // 기울기 각도
		FW,                 // 글꼴 두께
		FALSE,                     // 이탤릭
		FALSE,                     // 밑줄
		0,                         // 취소선
		ANSI_CHARSET,              // 문자셋
		OUT_DEFAULT_PRECIS,        // 출력 정밀도
		CLIP_DEFAULT_PRECIS,       // 클리핑 정밀도
		DEFAULT_QUALITY,           // 출력 품질
		DEFAULT_PITCH | FF_SWISS,  // 피치 및 패밀리
		_T("Arial"));              // 글꼴 이름

	m_setFont_for_m_font_menu(IDC_TEXT1);
	m_setFont_for_m_font_menu(IDC_TEXT2);
	m_setFont_for_m_font_menu(IDC_TEXT3);
	m_setFont_for_m_font_menu(IDC_TEXT4);
	m_setFont_for_m_font_menu(IDC_TEXT5);
	m_setFont_for_m_font_menu(IDC_TEXT6);
	m_setFont_for_m_font_menu(IDC_TEXT7);
	m_setFont_for_m_font_menu(IDC_TEXT8);
	m_setFont_for_m_font_menu(IDC_TEXT9);
}
void CMFCKIOSKDlg::m_setFont_price(int fontsize, int FW)
{
	// TODO: 여기에 구현 코드 추가.
	m_font_price.CreateFont(
		fontsize,                        // 높이
		0,                         // 폭
		0,                         // 기울기 각도
		0,                         // 기울기 각도
		FW,                 // 글꼴 두께
		FALSE,                     // 이탤릭
		FALSE,                     // 밑줄
		0,                         // 취소선
		ANSI_CHARSET,              // 문자셋
		OUT_DEFAULT_PRECIS,        // 출력 정밀도
		CLIP_DEFAULT_PRECIS,       // 클리핑 정밀도
		DEFAULT_QUALITY,           // 출력 품질
		DEFAULT_PITCH | FF_SWISS,  // 피치 및 패밀리
		_T("Arial"));              // 글꼴 이름
	m_setFont_for_m_font_price(IDC_PRICE1);
	m_setFont_for_m_font_price(IDC_PRICE2);
	m_setFont_for_m_font_price(IDC_PRICE3);
	m_setFont_for_m_font_price(IDC_PRICE4);
	m_setFont_for_m_font_price(IDC_PRICE5);
	m_setFont_for_m_font_price(IDC_PRICE6);
	m_setFont_for_m_font_price(IDC_PRICE7);
	m_setFont_for_m_font_price(IDC_PRICE8);
	m_setFont_for_m_font_price(IDC_PRICE9);

}
void CMFCKIOSKDlg::m_setFont_order(int fontsize, int FW)
{
	// TODO: 여기에 구현 코드 추가.
	m_font_order.CreateFont(
		fontsize,                        // 높이
		0,                         // 폭
		0,                         // 기울기 각도
		0,                         // 기울기 각도
		FW,                 // 글꼴 두께
		FALSE,                     // 이탤릭
		FALSE,                     // 밑줄
		0,                         // 취소선
		ANSI_CHARSET,              // 문자셋
		OUT_DEFAULT_PRECIS,        // 출력 정밀도
		CLIP_DEFAULT_PRECIS,       // 클리핑 정밀도
		DEFAULT_QUALITY,           // 출력 품질
		DEFAULT_PITCH | FF_SWISS,  // 피치 및 패밀리
		_T("Arial"));              // 글꼴 이름
	m_setFont_for_m_font_order(IDC_TEXT_ORDER19);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER2);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER3);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER4);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER5);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER6);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER7);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER8);
}
void CMFCKIOSKDlg::m_setFont_order_amount(int fontsize, int FW)
{
	// TODO: 여기에 구현 코드 추가.
	m_font_order.CreateFont(
		fontsize,                        // 높이
		0,                         // 폭
		0,                         // 기울기 각도
		0,                         // 기울기 각도
		FW,                 // 글꼴 두께
		FALSE,                     // 이탤릭
		FALSE,                     // 밑줄
		0,                         // 취소선
		ANSI_CHARSET,              // 문자셋
		OUT_DEFAULT_PRECIS,        // 출력 정밀도
		CLIP_DEFAULT_PRECIS,       // 클리핑 정밀도
		DEFAULT_QUALITY,           // 출력 품질
		DEFAULT_PITCH | FF_SWISS,  // 피치 및 패밀리
		_T("Arial"));              // 글꼴 이름
	m_setFont_order_amount(1072);
	m_setFont_order_amount(1073);
	m_setFont_order_amount(1074);
	m_setFont_order_amount(1075);
	m_setFont_order_amount(1077);
	m_setFont_order_amount(1078);
	m_setFont_order_amount(1079);
	m_setFont_order_amount(1080);
}

void CMFCKIOSKDlg::m_setFont_editbox(int fontsize, int FW)
{
	m_font_editbox.CreateFont(
		fontsize,                        // 높이
		0,                         // 폭
		0,                         // 기울기 각도
		0,                         // 기울기 각도
		FW,                 // 글꼴 두께
		FALSE,                     // 이탤릭
		FALSE,                     // 밑줄
		0,                         // 취소선
		ANSI_CHARSET,              // 문자셋
		OUT_DEFAULT_PRECIS,        // 출력 정밀도
		CLIP_DEFAULT_PRECIS,       // 클리핑 정밀도
		DEFAULT_QUALITY,           // 출력 품질
		DEFAULT_PITCH | FF_SWISS,  // 피치 및 패밀리
		_T("Arial"));              // 글꼴 이름
	m_setFont_for_m_font_edit(IDC_EDIT1);
	m_setFont_for_m_font_edit(IDC_EDIT2);
	m_setFont_for_m_font_edit(IDC_EDIT3);
	m_setFont_for_m_font_edit(IDC_EDIT4);
	m_setFont_for_m_font_edit(IDC_EDIT5);
	m_setFont_for_m_font_edit(IDC_EDIT6);
	m_setFont_for_m_font_edit(IDC_EDIT7);
	m_setFont_for_m_font_edit(IDC_EDIT8);
}

void CMFCKIOSKDlg::m_setFont_ordersum(int fontsize, int FW)
{
	// TODO: 여기에 구현 코드 추가.
	m_font_ordersum.CreateFont(
		fontsize,                        // 높이
		0,                         // 폭
		0,                         // 기울기 각도
		0,                         // 기울기 각도
		FW,                 // 글꼴 두께
		FALSE,                     // 이탤릭
		FALSE,                     // 밑줄
		0,                         // 취소선
		ANSI_CHARSET,              // 문자셋
		OUT_DEFAULT_PRECIS,        // 출력 정밀도
		CLIP_DEFAULT_PRECIS,       // 클리핑 정밀도
		DEFAULT_QUALITY,           // 출력 품질
		DEFAULT_PITCH | FF_SWISS,  // 피치 및 패밀리
		_T("Arial"));              // 글꼴 이름

	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER1_SUM);
	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER2_SUM);
	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER3_SUM);
	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER4_SUM);
	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER5_SUM);
	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER6_SUM);
	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER7_SUM);
	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER8_SUM);

}
void CMFCKIOSKDlg::m_setFont_allsum(int fontsize, int FW)
{
	// TODO: 여기에 구현 코드 추가.
	m_font_allsum.CreateFont(
		fontsize,                        // 높이
		0,                         // 폭
		0,                         // 기울기 각도
		0,                         // 기울기 각도
		FW,                 // 글꼴 두께
		FALSE,                     // 이탤릭
		FALSE,                     // 밑줄
		0,                         // 취소선
		ANSI_CHARSET,              // 문자셋
		OUT_DEFAULT_PRECIS,        // 출력 정밀도
		CLIP_DEFAULT_PRECIS,       // 클리핑 정밀도
		DEFAULT_QUALITY,           // 출력 품질
		DEFAULT_PITCH | FF_SWISS,  // 피치 및 패밀리
		_T("Arial"));              // 글꼴 이름

	m_setFont_for_m_font_allsum(1060);
}

void CMFCKIOSKDlg::OnClickedButtonCoffee()
{
	//coffee 메뉴를 클릭했을 때 메뉴판
	m_buttonCoffee = true;
	ClickedCoffeeUp();
	m_buttonCraft = m_buttonTea = m_buttonBread = false;
	m_buttonCoffeeDown = false;
	showSoldOut();
}

void CMFCKIOSKDlg::OnClickedButtonCraft()
{
	//craft 메뉴를 클릭했을 때 메뉴판
	m_buttonCraft = true;
	ClickedCraftUp();
	m_buttonCoffee = m_buttonTea = m_buttonBread = false;

	showSoldOut();
}

void CMFCKIOSKDlg::OnClickedButtonTea()
{
	//tea 메뉴를 클릭했을 때 메뉴판
	m_buttonTea = true;
	ClickedTeaUp();
	m_buttonCoffee = m_buttonCraft = m_buttonBread  = false;

	showSoldOut();
}

void CMFCKIOSKDlg::OnClickedButtonBread()
{
	//bread 메뉴를 클릭했을 때 메뉴판
	m_buttonBread = true;
	ClickedBreadUp();
	m_buttonCoffee = m_buttonCraft = m_buttonTea = false;

	showSoldOut();
}

void CMFCKIOSKDlg::OnClickedButtonUp()
{
	if (m_buttonCoffee)
	{
		//위 버튼 눌렀을 때(coffee)
		ClickedCoffeeUp();
		m_buttonCoffeeDown = false;
		showSoldOut();
	}
	else if (m_buttonCraft)
	{
		//위 버튼 눌렀을 때(craft)
		ClickedCraftUp();
		m_buttonCraftDown = false;
		showSoldOut();
	}
	else if (m_buttonTea)
	{
		//위 버튼 눌렀을 때(tea)
		ClickedTeaUp();
		m_buttonTeaDown = false;
		showSoldOut();
	}
	else if (m_buttonBread)
	{
		//위 버튼 눌렀을 때(bread)
		ClickedBreadUp();
		m_buttonBreadDown = false;
		showSoldOut();
	}
}

void CMFCKIOSKDlg::OnClickedButtonDown()
{
	if (m_buttonCoffee)
	{
		ClickedCoffeeDown();
		m_buttonCoffeeDown = true;
		showSoldOut();

	}
	else if (m_buttonCraft)
	{
		ClickedCraftDown();
		m_buttonCraftDown = true;
		showSoldOut();
	}
	else if (m_buttonTea)
	{
		ClickedTeaDown();
		m_buttonTeaDown = true;
		showSoldOut();

	}
	else if (m_buttonBread)
	{
		ClickedBreadDown();
		m_buttonBreadDown = true;
		showSoldOut();
	}
}
void CMFCKIOSKDlg::ClickedCoffeeUp()
{
	ClearTextFields();
	m_buttonCoffee = true;
	if (m_korean) {                                       
		m_Text1.SetWindowTextA(_T("밀키스"));
		m_Text2.SetWindowTextA(_T("마운틴_듀"));
		m_Text3.SetWindowTextA(_T("프렌치_카페"));
		m_Text4.SetWindowTextA(_T("코카콜라_제로"));
		m_Text5.SetWindowTextA(_T("환타_오렌지"));
		m_Text6.SetWindowTextA(_T("스프라이트"));
		m_Text7.SetWindowTextA(_T("사과에이드"));
		m_Text8.SetWindowTextA(_T("스타벅스_카페라떼(ice)"));
		m_Text9.SetWindowTextA(_T("썬업_오렌지"));

		m_Price1.SetWindowTextA(_T("1,500원"));
		m_Price2.SetWindowTextA(_T("1,400원"));
		m_Price3.SetWindowTextA(_T("2,900원"));
		m_Price4.SetWindowTextA(_T("1,500원"));
		m_Price5.SetWindowTextA(_T("1,500원"));
		m_Price6.SetWindowTextA(_T("1,500원"));
		m_Price7.SetWindowTextA(_T("2,300원"));
		m_Price8.SetWindowTextA(_T("3,400원"));
		m_Price9.SetWindowTextA(_T("2,500원"));

	}
	InvalidateRect(&r1, TRUE);
	UpdateWindow();

	//bitmap 이미지 넣기
	HBITMAP hbit;
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C1));
	m_pictureControl1.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C2));
	m_pictureControl2.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C3));
	m_pictureControl3.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C4));
	m_pictureControl4.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C5));
	m_pictureControl5.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C6));
	m_pictureControl6.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C7));
	m_pictureControl7.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C8));
	m_pictureControl8.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C9));
	m_pictureControl9.SetBitmap(hbit);
	m_buttonCraft = m_buttonTea = m_buttonBread = false;

	showSoldOut();
}

void CMFCKIOSKDlg::ClickedCoffeeDown()
{
	
	ClearTextFields();
	m_buttonCoffee = true;
	if (m_korean) {                                        
		m_Text1.SetWindowTextA(_T("물"));
		m_Text2.SetWindowTextA(_T("티니핑음료수"));

		m_Price1.SetWindowTextA(_T("700원"));
		m_Price2.SetWindowTextA(_T("1,700원"));
	}

	InvalidateRect(&r1, TRUE);
	UpdateWindow();

	//bitmap 이미지 넣기
	HBITMAP hbit;
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C10));
	m_pictureControl1.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C11));
	m_pictureControl2.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl3.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl4.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl5.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl6.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl7.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl8.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl9.SetBitmap(hbit);
	m_buttonCraft = m_buttonTea = m_buttonBread = false;
	m_buttonBreadDown = false;
	m_buttonCoffeeDown = false;
	showSoldOut();
}

void CMFCKIOSKDlg::ClickedCraftUp()
{
	// 제조음료 메뉴를 클릭했을 때 = 스낵 
	//UP화면
	ClearTextFields();
	m_buttonCraft = true;
	if (m_korean) {                                        
		m_Text1.SetWindowTextA(_T("콘칲"));
		m_Text2.SetWindowTextA(_T("고래밥"));
		m_Text3.SetWindowTextA(_T("꼬북칩"));
		m_Text4.SetWindowTextA(_T("오사쯔"));
		m_Text5.SetWindowTextA(_T("새우깡"));
		
		m_Price1.SetWindowTextA(_T("1,500원"));
		m_Price2.SetWindowTextA(_T("1,500원"));
		m_Price3.SetWindowTextA(_T("1,700원"));
		m_Price4.SetWindowTextA(_T("1,500원"));
		m_Price5.SetWindowTextA(_T("1,500원"));
	}
	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r1, TRUE);
	UpdateWindow();

	//bitmap 이미지 넣기
	HBITMAP hbit;
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_CR1));
	m_pictureControl1.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_CR2));
	m_pictureControl2.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_CR3));
	m_pictureControl3.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_CR4));
	m_pictureControl4.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_CR5));
	m_pictureControl5.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl6.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl7.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl8.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl9.SetBitmap(hbit);
	m_buttonCoffee = m_buttonTea = m_buttonBread = false;
	m_buttonCoffeeDown = false;
	m_buttonBreadDown = false;

	showSoldOut();
}

void CMFCKIOSKDlg::ClickedCraftDown()
{
	// 제조음료 메뉴를 클릭했을 때
	//DOWN화면
	m_buttonCraft = true;
	m_buttonCoffee = m_buttonTea = m_buttonBread = false;

	showSoldOut();
}

void CMFCKIOSKDlg::ClickedTeaUp()
{
	//UP화면
	ClearTextFields();
	m_buttonTea = true;
	if (m_korean) {                                        //한국어
		m_Text1.SetWindowTextA(_T("콕찍어소시지"));
		m_Text2.SetWindowTextA(_T("떡하니불어라"));
		m_Text3.SetWindowTextA(_T("압도적_돈가스파스타"));
		m_Text4.SetWindowTextA(_T("짜파게티_순살찜닭"));
		m_Text5.SetWindowTextA(_T("고기많이_도시락"));
		m_Text6.SetWindowTextA(_T("소불고기_마파덮밥"));

		m_Price1.SetWindowTextA(_T("5,300원"));
		m_Price2.SetWindowTextA(_T("5,500원"));
		m_Price3.SetWindowTextA(_T("6,400원"));
		m_Price4.SetWindowTextA(_T("6,900원"));
		m_Price5.SetWindowTextA(_T("5,100원"));
		m_Price6.SetWindowTextA(_T("6,100원"));
	}

	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r1, TRUE);
	UpdateWindow();

	//bitmap 이미지 넣기
	HBITMAP hbit;
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_T1));
	m_pictureControl1.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_T2));
	m_pictureControl2.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_T3));
	m_pictureControl3.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_T4));
	m_pictureControl4.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_T5));
	m_pictureControl5.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_T6));
	m_pictureControl6.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl7.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl8.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl9.SetBitmap(hbit);
	m_buttonCoffee = m_buttonCraft = m_buttonBread = false;
	m_buttonCoffeeDown = false;
	m_buttonBreadDown = false;

	showSoldOut();
}

void CMFCKIOSKDlg::ClickedTeaDown()
{
	// 차 메뉴를 클릭했을 때
	//DOWN화면
	m_buttonTea = true;
	m_buttonCoffee = m_buttonCraft = m_buttonBread = false;

	showSoldOut();

}
void CMFCKIOSKDlg::ClickedBreadUp()
{
	// 제과류 메뉴를 클릭했을 때
    //UP화면
	ClearTextFields();
	m_buttonBread = true;
	if (m_korean) {                                        //한국어
		m_Text1.SetWindowTextA(_T("육개장_작은컵"));
		m_Text2.SetWindowTextA(_T("신라면_투움바"));
		m_Text3.SetWindowTextA(_T("신라면_블랙"));
		m_Text4.SetWindowTextA(_T("마열라면"));
		m_Text5.SetWindowTextA(_T("진라면_매운맛"));
		m_Text6.SetWindowTextA(_T("불닭볶음면"));
		m_Text7.SetWindowTextA(_T("라면사리"));
		m_Text8.SetWindowTextA(_T("진라면_순한맛"));
		m_Text9.SetWindowTextA(_T("참깨라면_볶음면"));

		m_Price1.SetWindowTextA(_T("1,000원"));
		m_Price2.SetWindowTextA(_T("2,000원"));
		m_Price3.SetWindowTextA(_T("1,900원"));
		m_Price4.SetWindowTextA(_T("1,800원"));
		m_Price5.SetWindowTextA(_T("900원"));
		m_Price6.SetWindowTextA(_T("900원"));
		m_Price7.SetWindowTextA(_T("500원"));
		m_Price8.SetWindowTextA(_T("900원"));
		m_Price9.SetWindowTextA(_T("2,200원"));
	}

	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r1, TRUE);
	UpdateWindow();

	//bitmap 이미지 넣기
	HBITMAP hbit;
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B1));
	m_pictureControl1.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B2));
	m_pictureControl2.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B3));
	m_pictureControl3.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B4));
	m_pictureControl4.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B5));
	m_pictureControl5.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B6));
	m_pictureControl6.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B7));
	m_pictureControl7.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B8));
	m_pictureControl8.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B9));
	m_pictureControl9.SetBitmap(hbit);
	m_buttonCoffee = m_buttonCraft = m_buttonTea = false;
	m_buttonCoffeeDown = false;
	m_buttonBreadDown = false;

	showSoldOut();
}

void CMFCKIOSKDlg::ClickedBreadDown()
{
	// 제과류 메뉴를 클릭했을 때
	//DOWN화면
	ClearTextFields();
	m_buttonBread = true;
	m_buttonBreadDown = true;
	
	if (m_korean) {                                        //한국어
		m_Text1.SetWindowTextA(_T("삼양라면"));
		m_Price1.SetWindowTextA(_T("850원"));
	}
	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r1, TRUE);
	UpdateWindow();

	//bitmap 이미지 넣기
	HBITMAP hbit;
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B10));
	m_pictureControl1.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl2.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl3.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl4.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl5.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl6.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl7.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl8.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl9.SetBitmap(hbit);
	m_buttonCoffee = m_buttonCraft = m_buttonTea = false;
	m_buttonCoffeeDown = false;
	
	showSoldOut();
}

void CMFCKIOSKDlg::OnClickedButtonKorean()
{
	// 한국어 버튼 클릭했을 때
	m_korean = true;
	m_english = m_chinese = false;
	if (m_buttonCoffee) {
		if (m_buttonCoffeeDown) {
			ClickedCoffeeDown();
			showSoldOut();
		}
		else
		{
			ClickedCoffeeUp();
			showSoldOut();
		}
	}
	else if (m_buttonCraft) {
		if (m_buttonCraftDown) {
			ClickedCraftDown();
			showSoldOut();
		}
		else
		{
			ClickedCraftUp();
			showSoldOut();
		}
	}
	else if (m_buttonTea) {
		if (m_buttonTeaDown) {
			ClickedTeaDown();
			showSoldOut();
		}
		else
		{
			ClickedTeaUp();
			showSoldOut();
		}
	}
	else if (m_buttonBread) {
		if (m_buttonBreadDown) {
			ClickedBreadDown();
			showSoldOut();
		}
		else {
			ClickedBreadUp();
			showSoldOut();
		}
	}
}


void CMFCKIOSKDlg::ClearTextFields()
{
		//텍스트 초기화
		SetDlgItemText(IDC_TEXT1, _T(""));
		SetDlgItemText(IDC_TEXT2, _T(""));
		SetDlgItemText(IDC_TEXT3, _T(""));
		SetDlgItemText(IDC_TEXT4, _T(""));
		SetDlgItemText(IDC_TEXT5, _T(""));
		SetDlgItemText(IDC_TEXT6, _T(""));
		SetDlgItemText(IDC_TEXT7, _T(""));
		SetDlgItemText(IDC_TEXT8, _T(""));
		SetDlgItemText(IDC_TEXT9, _T(""));

		SetDlgItemText(IDC_PRICE1, _T(""));
		SetDlgItemText(IDC_PRICE2, _T(""));
		SetDlgItemText(IDC_PRICE3, _T(""));
		SetDlgItemText(IDC_PRICE4, _T(""));
		SetDlgItemText(IDC_PRICE5, _T(""));
		SetDlgItemText(IDC_PRICE6, _T(""));
		SetDlgItemText(IDC_PRICE7, _T(""));
		SetDlgItemText(IDC_PRICE8, _T(""));
		SetDlgItemText(IDC_PRICE9, _T(""));
}

HBRUSH CMFCKIOSKDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//버튼 투명화 함수
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	int nRet = pWnd->GetDlgCtrlID();
	if (nRet == IDC_BUTTON_KOREAN)  
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_ENGLISH)  
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_CHINESE)  
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_UP)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_DOWN)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_COFFEE)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_CRAFT)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_TEA)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_BREAD)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_TOGO)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_HERE)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	return hbr;
}

void CMFCKIOSKDlg::OnClickedButtonHere()
{
	if (isInitial(m_OrderList[0])) {
		//AfxMessageBox("주문 리스트가 비어있습니다!");
		return;
	}

	// 매장에서 버튼을 눌렀을 때
	if (m_dlgPay.GetSafeHwnd()) {
		m_dlgPay.DestroyWindow();
	}
	m_dlgPay.DoModal();
	if (m_dlgPay.checkPayComplete()) { //결제 성공시


		initOrderList_ALL(); //주문리스트 구조체 초기화 & 화면 새로고침
	}
	else
		; //결제 실패시
}

void CMFCKIOSKDlg::OnClickedButtonTogo()
{
	if (isInitial(m_OrderList[0])) {
		//AfxMessageBox("주문 리스트가 비어있습니다!");
		return;
	}

	// 포장 버튼을 눌렀을 때
	if (m_dlgPay.GetSafeHwnd()) {
		m_dlgPay.DestroyWindow();
	}
	m_dlgPay.DoModal();

	if (m_dlgPay.checkPayComplete()) { //결제 성공시


		initOrderList_ALL(); //주문리스트 구조체 초기화 & 화면 새로고침
	}
	else
		; //결제 실패시 
}

void CMFCKIOSKDlg::OnStnClickedTextOrder13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
void CMFCKIOSKDlg::OnStnClickedTextOrder3Sum()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
void CMFCKIOSKDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
		
		CRect myRect(108, 170, 300, 370); 
		CRect myRect2(468, 170, 668, 370);
		CRect myRect3(808, 170, 1008, 370);
		CRect myRect4(108, 450, 300, 650);
		CRect myRect5(458, 450, 658, 650);
		CRect myRect6(808, 450, 1008, 650);
		CRect myRect7(108, 750, 300, 950);
		CRect myRect8(468, 750, 668, 950);
		CRect myRect9(808, 750, 1008, 950);

		if (TRUE) { 

			if (myRect.PtInRect(point))
			{
				Add_List(1);
				
			}
			if (myRect2.PtInRect(point))
			{
				// 2번 매뉴를 클릭했을 때 
				Add_List(2);
			}
			if (myRect3.PtInRect(point))
			{
				// 3번 매뉴를 클릭했을 때 
				Add_List(3);
			}
			if (myRect4.PtInRect(point))
			{
				// 4번 매뉴를 클릭했을 때 
				Add_List(4);

			}if (myRect5.PtInRect(point))
			{
				// 5번 매뉴를 클릭했을 때 
				Add_List(5);

			}if (myRect6.PtInRect(point))
			{
				// 6번 매뉴를 클릭했을 때 
				Add_List(6);

			}if (myRect7.PtInRect(point))
			{
				// 7번 매뉴를 클릭했을 때 
				Add_List(7);

			}if (myRect8.PtInRect(point))
			{
				// 8번 매뉴를 클릭했을 때 
				Add_List(8);

			}
			if (myRect9.PtInRect(point))
			{
				// 9번 매뉴를 클릭했을 때 
				Add_List(9);

			}
		}
	}
	
void CMFCKIOSKDlg::OnStnClickedTextOrder18()
{
}
void CMFCKIOSKDlg::OnStnClickedTextOrder12()
{}

void CMFCKIOSKDlg::OnStnClickedTextOrder19()
{
}

void CMFCKIOSKDlg::Add_List(int MENUPOS)
{
	if (m_buttonCoffee && !m_buttonCoffeeDown) { // 커피의 경우  = 음료
		switch (MENUPOS) {
		case 1:
			if (InsertOrder(밀키스))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 2:
			if (InsertOrder(마운틴_듀))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 3:
			if (InsertOrder(프렌치_카페))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 4:
			if (InsertOrder(코카콜라_제로))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 5:
			if (InsertOrder(환타_오렌지))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 6:
			if (InsertOrder(스프라이트))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 7:
			if (InsertOrder(사과에이드))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 8:
			if (InsertOrder(스타벅스_카페라떼))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 9:
			if (InsertOrder(썬업_오렌지))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		}
	}
	else if (m_buttonCoffeeDown) {	//음료
		switch (MENUPOS) {
		case 1:
			if (InsertOrder(물))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 2:
			if (InsertOrder(티니핑_음료수))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		}
	}
	else if (m_buttonTea) { // 차의 경우		//도시락
		switch (MENUPOS) {
		case 1:
			if (InsertOrder(콕찍어소시지))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 2:
			if (InsertOrder(떡하니붙어라))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 3:
			if (InsertOrder(압도적_돈가스파스타))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 4:
			if (InsertOrder(짜파게티_순살찜닭))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 5:
			if (InsertOrder(고기많이_도시락))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 6:
			if (InsertOrder(소불고기_마파덮밥))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		}
	}
	else if (m_buttonCraft) { // 제조음료의 경우	// 스낵
		switch (MENUPOS) {
		case 1:
			if (InsertOrder(콘칲))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 2:
			if (InsertOrder(고래밥))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 3:
			if (InsertOrder(꼬북칩))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 4:
			if (InsertOrder(오사쯔))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 5:
			if (InsertOrder(새우깡))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		}
	}
	else if (m_buttonBread && !m_buttonBreadDown) { // 제과류의 경우		//라면
		switch (MENUPOS) {
		case 1:
			if (InsertOrder(육개장_작은컵))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 2:
			if (InsertOrder(신라면_투움바))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 3:
			if (InsertOrder(신라면_블랙))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 4:
			if (InsertOrder(마열라면))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 5:
			if (InsertOrder(진라면_매운맛))
				showOrderList();
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 6:
			if (InsertOrder(불닭볶음면)) {
				showOrderList();
			}
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 7:
			if (InsertOrder(라면사리)) {
				showOrderList();
			}
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 8:
			if (InsertOrder(진라면_순한맛)) {
				showOrderList();
			}
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
				
			break;
		case 9:
			if (InsertOrder(참깨라면_볶음면)) {
				showOrderList();
			}
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));

			break;
		case 10:
			if (InsertOrder(삼양라면)) {
				showOrderList();
			}
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));

			break;
		}
	
		}
	else if (m_buttonBreadDown) {	//라면
		switch (MENUPOS) {
		case 1:
			if (InsertOrder(삼양라면)) {
				showOrderList();
			}
			else
				if (m_Flag_SOLDOUT) m_Flag_SOLDOUT = true; else MessageBox(_T("주문 리스트가 꽉 찼습니다!"));

			break;

		}
	}
}

int CMFCKIOSKDlg::InsertOrder(int p_Order) {
	
	//struct OrderList {
	//	CString mName; //매뉴명 
	//	int mQty; // 수량 
	//	int mSum; // 가격 총합
	
	//현재 품절 상태인지 확인
	if (isSoldOut(Stock, getName(p_Order))) { //품절일 경우
		MessageBox(_T("품절인 상품입니다"));
		m_Flag_SOLDOUT = TRUE;

		return FALSE; // 주문 실 패 
	}

	//주문 리스트에 중복이 있는지 확인
	for (int i = 0; i < 8; i++) {
		if (m_OrderList[i].mName == p_Order) {
			m_OrderList[i].mQty++; // 리스트 안에 같은 매뉴가 있으면 수량 + 1
			m_OrderList[i].mSum = getPrice(p_Order) * m_OrderList[i].mQty; // 가격 총합 계산

			minStock(Stock, getName(p_Order), 1); //주문정보 재고에 반영
			showSoldOut();
			return TRUE;
		}
	}

	//빈 자리에 넣음
	for (int i = 0; i < 8; i++) { 
		if (isInitial(m_OrderList[i])){ // 초기화 판단
			m_OrderList[i].mName = p_Order; //매뉴 이름 설정
			m_OrderList[i].mQty++; // 수량 +1
			m_OrderList[i].mSum = getPrice(p_Order) * m_OrderList[i].mQty; // 가격 총합 계산

			minStock(Stock, getName(p_Order), 1); //주문정보 재고에 반영

			return TRUE; //주문 성공
		}
	}	
	return FALSE; //  주문 실패 (주문 리스트에 빈 자리가 없음 !! ) 
}
bool CMFCKIOSKDlg::isInitial(struct OrderList Orderlist)
{
	//구조체가 초기화 상태인지 확인하는 함수
	if (Orderlist.mName == 0)
		return TRUE; //빈 배열 맞음
	else
		return FALSE; //빈 배열 아님
}
int CMFCKIOSKDlg::getPrice(int item_number)
{
	// 매뉴 이름 매크로를 받으면 가격을 리턴하는 함수
	if (item_number == 밀키스)
		return 1500;
	else if (item_number == 마운틴_듀)
		return 1400;
	else if (item_number == 프렌치_카페)
		return 2900;
	else if (item_number == 코카콜라_제로)
		return 1500;
	else if (item_number == 환타_오렌지)
		return 1500;
	else if (item_number == 스프라이트)
		return 1500;
	else if (item_number == 사과에이드)
		return 2300;
	else if (item_number == 스타벅스_카페라떼)
		return 3400;
	else if (item_number == 썬업_오렌지)
		return 2500;
	else if (item_number == 물)
		return 700;
	else if (item_number == 티니핑_음료수)
		return 1700;
	else if (item_number == 육개장_작은컵)
		return 1000;
	else if (item_number == 신라면_투움바)
		return 2000;
	else if (item_number == 신라면_블랙)
		return 1900;
	else if (item_number == 마열라면)
		return 1800;
	else if (item_number == 진라면_매운맛)
		return 900;
	else if (item_number == 불닭볶음면)
		return 900;
	else if (item_number == 라면사리)
		return 500;
	else if (item_number == 진라면_순한맛)
		return 900;
	else if (item_number == 참깨라면_볶음면)
		return 2200;
	else if (item_number == 삼양라면)
		return 850;
	else if (item_number == 콕찍어소시지)
		return 5300;
	else if (item_number == 떡하니붙어라)
		return 5500;
	else if (item_number == 압도적_돈가스파스타)
		return 6400;
	else if (item_number == 짜파게티_순살찜닭)
		return 6900;
	else if (item_number == 고기많이_도시락)
		return 5100;
	else if (item_number == 소불고기_마파덮밥)
		return 6100;
	else if (item_number == 콘칲)
		return 1500;
	else if (item_number == 고래밥)
		return 1500;
	else if (item_number == 꼬북칩)
		return 1700;
	else if (item_number == 오사쯔)
		return 1500;
	else if (item_number == 새우깡)
		return 1500;
	else
		return -1; // ERROR : 알 수 없는 매뉴
}
//리스트 삭제 함수
int CMFCKIOSKDlg::deleteOrder(int listPosition) //몇 번째 리스트인지
{
	addStock(Stock, getName(m_OrderList[listPosition - 1].mName), m_OrderList[listPosition - 1].mQty); // 주문 리스트에 있던 수량 만큼 재고에 +

	initOrder_one(listPosition);

	for (int i = 1; i < 8; i++) {
		 
		if (isInitial(m_OrderList[i - 1])) {
			m_OrderList[i - 1] = m_OrderList[i];
			initOrder_one(i + 1);

		}	
	}
	refreshOrder();

	showOrderList();
	
	refreshAll_Images(); //매뉴 이미지 전체 새로고침
	showSoldOut(); // 품절 상품에 SOLDOUTT 이미지 표시 
	return 0;
}
int CMFCKIOSKDlg::initOrder_one(int listPosition) //구조체 하나만 초기화
{
	int n = listPosition - 1;
	// listPosition번째 구조체 초기화
	m_OrderList[n].mName = 0;
	m_OrderList[n].mQty = 0;
	m_OrderList[n].mSum = 0;

	return 0;
}

int CMFCKIOSKDlg::initOrder_all() //구조체 전체 초기화
{
	for (int i = 0; i < 8; i++) {
		m_OrderList[i].mName = 0;
		m_OrderList[i].mQty = 0;
		m_OrderList[i].mSum = 0;
	}
	return 0;
}

int CMFCKIOSKDlg::showOrderList() // 주문 리스트 화면에 표시
{
	CString mQty[8];
	CString mSum[8];
	CString ALLSUM;
	refreshOrder();
	//주문 리스트 매뉴 이름 추가 
	if (!isInitial(m_OrderList[0])) // 구조체에 내용이 있을 경우
		m_orderlist_1.SetWindowTextA(_T(getName(m_OrderList[0].mName)));
	
	if (!isInitial(m_OrderList[1])) // 구조체에 내용이 있을 경우
		m_orderlist_2.SetWindowTextA(_T(getName(m_OrderList[1].mName)));
	if (!isInitial(m_OrderList[2])) // 구조체에 내용이 있을 경우
		m_orderlist_3.SetWindowTextA(_T(getName(m_OrderList[2].mName)));
	if (!isInitial(m_OrderList[3])) // 구조체에 내용이 있을 경우
		m_orderlist14_2.SetWindowTextA(_T(getName(m_OrderList[3].mName)));
	if (!isInitial(m_OrderList[4])) // 구조체에 내용이 있을 경우
		m_orderlist_5.SetWindowTextA(_T(getName(m_OrderList[4].mName)));
	if (!isInitial(m_OrderList[5])) // 구조체에 내용이 있을 경우
		m_orderlist_6.SetWindowTextA(_T(getName(m_OrderList[5].mName)));
	if (!isInitial(m_OrderList[6])) // 구조체에 내용이 있을 경우
		m_orderlist_7.SetWindowTextA(_T(getName(m_OrderList[6].mName)));
	if (!isInitial(m_OrderList[7])) // 구조체에 내용이 있을 경우
		m_orderlist_8.SetWindowTextA(_T(getName(m_OrderList[7].mName)));

	//주문 리스트 매뉴 수량 추가
	if (!isInitial(m_OrderList[0])) { // 구조체에 내용이 있을 경우
		mQty[0].Format(_T("%d"), m_OrderList[0].mQty);
		m_edit1.SetWindowTextA(mQty[0]);
	}
	if (!isInitial(m_OrderList[1])) { // 구조체에 내용이 있을 경우
		mQty[1].Format(_T("%d"), m_OrderList[1].mQty);
		m_edit2.SetWindowTextA(mQty[1]);
	}if (!isInitial(m_OrderList[2])) { // 구조체에 내용이 있을 경우
		mQty[2].Format(_T("%d"), m_OrderList[2].mQty);
		m_edit3.SetWindowTextA(mQty[2]);
	}if (!isInitial(m_OrderList[3])) { // 구조체에 내용이 있을 경우
		mQty[3].Format(_T("%d"), m_OrderList[3].mQty);
		m_edit4.SetWindowTextA(mQty[3]);
	}if (!isInitial(m_OrderList[4])) { // 구조체에 내용이 있을 경우
		mQty[4].Format(_T("%d"), m_OrderList[4].mQty);
		m_edit5.SetWindowTextA(mQty[4]);
	}if (!isInitial(m_OrderList[5])) { // 구조체에 내용이 있을 경우
		mQty[5].Format(_T("%d"), m_OrderList[5].mQty);
		m_edit6.SetWindowTextA(mQty[5]);
	}if (!isInitial(m_OrderList[6])) { // 구조체에 내용이 있을 경우
		mQty[6].Format(_T("%d"), m_OrderList[6].mQty);
		m_edit7.SetWindowTextA(mQty[6]);
	}if (!isInitial(m_OrderList[7])) { // 구조체에 내용이 있을 경우
		mQty[7].Format(_T("%d"), m_OrderList[7].mQty);
		m_edit8.SetWindowTextA(mQty[7]);
	}
	//주문 리스트 가격합 추가
	if (!isInitial(m_OrderList[0])) { // 구조체에 내용이 있을 경우
		mSum[0].Format(_T("%d"), m_OrderList[0].mQty * getPrice(m_OrderList[0].mName));
		m_textOrderSum1.SetWindowTextA(mSum[0]);
	}
	if (!isInitial(m_OrderList[1])) { // 구조체에 내용이 있을 경우
		mSum[1].Format(_T("%d"), m_OrderList[1].mQty * getPrice(m_OrderList[1].mName));
		m_textOrderSum2.SetWindowTextA(mSum[1]);
	}if (!isInitial(m_OrderList[2])) { // 구조체에 내용이 있을 경우
		mSum[2].Format(_T("%d"), m_OrderList[2].mQty * getPrice(m_OrderList[2].mName));
		m_textOrderSum3.SetWindowTextA(mSum[2]);
	}if (!isInitial(m_OrderList[3])) { // 구조체에 내용이 있을 경우
		mSum[3].Format(_T("%d"), m_OrderList[3].mQty * getPrice(m_OrderList[3].mName));
		m_textOrderSum4.SetWindowTextA(mSum[3]);
	}if (!isInitial(m_OrderList[4])) { // 구조체에 내용이 있을 경우
		mSum[4].Format(_T("%d"), m_OrderList[4].mQty * getPrice(m_OrderList[4].mName));
		m_textOrderSum5.SetWindowTextA(mSum[4]);
	}if (!isInitial(m_OrderList[5])) { // 구조체에 내용이 있을 경우
		mSum[5].Format(_T("%d"), m_OrderList[5].mQty * getPrice(m_OrderList[5].mName));
		m_textOrderSum6.SetWindowTextA(mSum[5]);
	}if (!isInitial(m_OrderList[6])) { // 구조체에 내용이 있을 경우
		mSum[6].Format(_T("%d"), m_OrderList[6].mQty * getPrice(m_OrderList[6].mName));
		m_textOrderSum7.SetWindowTextA(mSum[6]);
	}if (!isInitial(m_OrderList[7])) { // 구조체에 내용이 있을 경우
		mSum[7].Format(_T("%d"), m_OrderList[7].mQty * getPrice(m_OrderList[7].mName));
		m_textOrderSum8.SetWindowTextA(mSum[7]);
	}

	for (int i = 0,sum = 0; i < 8; i++) {
		sum += m_OrderList[i].mSum;

		if (i == 7) {
			ALLSUM.Format(_T("%d"), sum);
			
			m_ALLSUM.SetWindowTextA(ALLSUM);
		}
	}
	return 0;
}
char* CMFCKIOSKDlg::getName(int name) {
		switch (name) {
		case 밀키스: return "밀키스";
		case 마운틴_듀: return "마운틴_듀";
		case 프렌치_카페: return "프렌치_카페";
		case 코카콜라_제로: return "코카콜라_제로";
		case 환타_오렌지: return "환타_오렌지";
		case 스프라이트: return "스프라이트";
		case 사과에이드: return "사과에이드";
		case 스타벅스_카페라떼: return "스타벅스_카페라떼";
		case 썬업_오렌지: return "썬업_오렌지";
		case 물: return "물";
		case 티니핑_음료수: return "티니핑_음료수";
		case 육개장_작은컵: return "육개장_작은컵";
		case 신라면_투움바: return "신라면_투움바";
		case 신라면_블랙: return "신라면_블랙";
		case 마열라면: return "마열라면";
		case 진라면_매운맛: return "진라면_매운맛";
		case 불닭볶음면: return "불닭볶음면";
		case 라면사리: return "라면사리";
		case 진라면_순한맛: return "진라면_순한맛";
		case 참깨라면_볶음면: return "참깨라면_볶음면";
		case 삼양라면: return "삼양라면";
		case 콕찍어소시지: return "콕찍어소시지";
		case 떡하니붙어라: return "떡하니붙어라";
		case 압도적_돈가스파스타: return "압도적_돈가스파스타";
		case 짜파게티_순살찜닭: return "짜파게티_순살찜닭";
		case 고기많이_도시락: return "고기많이_도시락";
		case 소불고기_마파덮밥: return "소불고기_마파덮밥";
		case 콘칲: return "콘칲";
		case 고래밥: return "고래밥";
		case 꼬북칩: return "꼬북칩";
		case 오사쯔: return "오사쯔";
		case 새우깡: return "약과";
		default: return "ERROR";
		}
	}

void CMFCKIOSKDlg::OnEnChangeEdit1()
{
}

void CMFCKIOSKDlg::OnBnClickedCanc1() // 주문 취소 버튼 1 
{
	deleteOrder(1);
}

void CMFCKIOSKDlg::OnBnClickedCanc2() // 주문 취소 버튼 2
{
	deleteOrder(2);
}
void CMFCKIOSKDlg::OnBnClickedCanc3()
{
	deleteOrder(3);
}

void CMFCKIOSKDlg::OnBnClickedCanc4()
{
	deleteOrder(4);
}

void CMFCKIOSKDlg::OnBnClickedCanc5()
{
	deleteOrder(5);
}

void CMFCKIOSKDlg::OnBnClickedCanc6()
{
	deleteOrder(6);
}
void CMFCKIOSKDlg::OnBnClickedCanc7()
{
	deleteOrder(7);
}
void CMFCKIOSKDlg::OnBnClickedCanc8()
{
	deleteOrder(8);
}

void CMFCKIOSKDlg::refreshOrder() //주문 리스트 텍스트 전체 초기화
{
	SetDlgItemText(IDC_EDIT1, _T(""));
	SetDlgItemText(IDC_EDIT2, _T(""));
	SetDlgItemText(IDC_EDIT3, _T(""));
	SetDlgItemText(IDC_EDIT4, _T(""));
	SetDlgItemText(IDC_EDIT5, _T(""));
	SetDlgItemText(IDC_EDIT6, _T(""));
	SetDlgItemText(IDC_EDIT7, _T(""));
	SetDlgItemText(IDC_EDIT8, _T(""));

	//매뉴 초기화
	setTextInit(1064);
	setTextInit(IDC_TEXT_ORDER12);
	setTextInit(IDC_TEXT_ORDER13);
	setTextInit(IDC_TEXT_ORDER14_2);
	setTextInit(IDC_TEXT_ORDER15);
	setTextInit(IDC_TEXT_ORDER16);
	setTextInit(IDC_TEXT_ORDER17);
	setTextInit(IDC_TEXT_ORDER18);

	//가격합 초기화
	setTextInit(IDC_TEXT_ORDER1_SUM);
	setTextInit(IDC_TEXT_ORDER2_SUM);
	setTextInit(IDC_TEXT_ORDER3_SUM);
	setTextInit(IDC_TEXT_ORDER4_SUM);
	setTextInit(IDC_TEXT_ORDER5_SUM);
	setTextInit(IDC_TEXT_ORDER6_SUM);
	setTextInit(IDC_TEXT_ORDER7_SUM);
	setTextInit(IDC_TEXT_ORDER8_SUM);

	//총 가격 초기화
	setTextInit(IDC_TEXT_ALLSUM);
}

void CMFCKIOSKDlg::setTextInit(int nID)
{
	CRect Rect;
	GetDlgItem(nID)->GetWindowRect(&Rect);
	ScreenToClient(&Rect);
	InvalidateRect(Rect);
	SetDlgItemText(nID, _T(""));
}

void CMFCKIOSKDlg::OnStnClickedTextOrder2Sum()
{
}

void CMFCKIOSKDlg::OnStnClickedTextOrder8Sum()
{
}

void CMFCKIOSKDlg::OnStnClickedletf1()
{
	if (m_OrderList[0].mQty == 1)
		return; // 주문 리스트의 수량이 1일 경우 수량 마이너스 버튼은 동작하지 않음
	minOrder(1);
	addStock(Stock, getName(m_OrderList[0].mName), 1);
	refreshAll_Images();

	showSoldOut();
}

void CMFCKIOSKDlg::OnStnClickedletf2()
{
	if (m_OrderList[1].mQty == 1)
		return; // 주문 리스트의 수량이 1일 경우 수량 마이너스 버튼은 동작하지 않음

	minOrder(2);
	addStock(Stock, getName(m_OrderList[1].mName), 1);
	refreshAll_Images();

	showSoldOut();

}
void CMFCKIOSKDlg::OnStnClickedletf3()
{
	if (m_OrderList[2].mQty == 1)
		return; // 주문 리스트의 수량이 1일 경우 수량 마이너스 버튼은 동작하지 않음

	minOrder(3);
	addStock(Stock, getName(m_OrderList[2].mName), 1);
	refreshAll_Images();

	showSoldOut();
}
void CMFCKIOSKDlg::OnStnClickedletf4()
{
	if (m_OrderList[3].mQty == 1)
		return; // 주문 리스트의 수량이 1일 경우 수량 마이너스 버튼은 동작하지 않음

	minOrder(4);
	addStock(Stock, getName(m_OrderList[3].mName), 1);
	refreshAll_Images();
	showSoldOut();
}
void CMFCKIOSKDlg::OnStnClickedletf5()
{
	if (m_OrderList[4].mQty == 1)
		return; // 주문 리스트의 수량이 1일 경우 수량 마이너스 버튼은 동작하지 않음

	minOrder(5);
	addStock(Stock, getName(m_OrderList[4].mName), 1);
	showSoldOut();
}
void CMFCKIOSKDlg::OnStnClickedletf6()
{
	if (m_OrderList[5].mQty == 1)
		return; // 주문 리스트의 수량이 1일 경우 수량 마이너스 버튼은 동작하지 않음

	minOrder(6);
	addStock(Stock, getName(m_OrderList[5].mName), 1);
	refreshAll_Images();
	showSoldOut();

}
void CMFCKIOSKDlg::OnStnClickedletf7()
{
	if (m_OrderList[6].mQty == 1)
		return; // 주문 리스트의 수량이 1일 경우 수량 마이너스 버튼은 동작하지 않음

	minOrder(7);
	addStock(Stock, getName(m_OrderList[6].mName), 1);
	refreshAll_Images();
	showSoldOut();
}
void CMFCKIOSKDlg::OnStnClickedletf8()
{
	if (m_OrderList[7].mQty == 1)
		return; // 주문 리스트의 수량이 1일 경우 수량 마이너스 버튼은 동작하지 않음

	minOrder(8);
	addStock(Stock, getName(m_OrderList[7].mName), 1);
	refreshAll_Images();
	showSoldOut();
}

void CMFCKIOSKDlg::OnStnClickedright1()
{
	if (isSoldOut(Stock, getName(m_OrderList[0].mName))) { //품절일 경우
		MessageBox(_T("품절인 상품입니다"));
		m_Flag_SOLDOUT = TRUE;
		return; // 주문 실 패 
	}
	addOrder(1);
	minStock(Stock, getName(m_OrderList[0].mName), 1);
	showSoldOut();

}

void CMFCKIOSKDlg::OnStnClickedright2()
{
	if (isSoldOut(Stock, getName(m_OrderList[1].mName))) { //품절일 경우
		MessageBox(_T("품절인 상품입니다"));
		m_Flag_SOLDOUT = TRUE;

		return; // 주문 실 패 
	}
	addOrder(2);
	minStock(Stock, getName(m_OrderList[1].mName), 1);
	showSoldOut();

}

void CMFCKIOSKDlg::OnStnClickedright3()
{
	if (isSoldOut(Stock, getName(m_OrderList[2].mName))) { //품절일 경우
		MessageBox(_T("품절인 상품입니다"));
		m_Flag_SOLDOUT = TRUE;

		return; // 주문 실 패 
	}
	addOrder(3);
	minStock(Stock, getName(m_OrderList[2].mName), 1);
	showSoldOut();
}

void CMFCKIOSKDlg::OnStnClickedright4()
{
	if (isSoldOut(Stock, getName(m_OrderList[3].mName))) { //품절일 경우
		MessageBox(_T("품절인 상품입니다"));
		m_Flag_SOLDOUT = TRUE;

		return; // 주문 실 패 
	}
	addOrder(4);
	minStock(Stock, getName(m_OrderList[3].mName), 1);

}
void CMFCKIOSKDlg::OnStnClickedright5()
{
	if (isSoldOut(Stock, getName(m_OrderList[4].mName))) { //품절일 경우
		MessageBox(_T("품절인 상품입니다"));
		m_Flag_SOLDOUT = TRUE;

		return; // 주문 실 패 
	}
	addOrder(5);
	minStock(Stock, getName(m_OrderList[4].mName), 1);

}
void CMFCKIOSKDlg::OnStnClickedright6()
{
	if (isSoldOut(Stock, getName(m_OrderList[5].mName))) { //품절일 경우
		MessageBox(_T("품절인 상품입니다"));
		m_Flag_SOLDOUT = TRUE;

		return; // 주문 실 패 
	}
	addOrder(6);
	minStock(Stock, getName(m_OrderList[5].mName), 1);
	showSoldOut();
}
void CMFCKIOSKDlg::OnStnClickedright7()
{
	if (isSoldOut(Stock, getName(m_OrderList[6].mName))) { //품절일 경우
		MessageBox(_T("품절인 상품입니다"));
		m_Flag_SOLDOUT = TRUE;

		return; // 주문 실 패 
	}
	addOrder(7);
	minStock(Stock, getName(m_OrderList[6].mName), 1);
	showSoldOut();
}
void CMFCKIOSKDlg::OnStnClickedright8()
{
	if (isSoldOut(Stock, getName(m_OrderList[7].mName))) { //품절일 경우
		MessageBox(_T("품절인 상품입니다"));
		m_Flag_SOLDOUT = TRUE;
		return; // 주문 실 패 
	}
	addOrder(8);
	minStock(Stock, getName(m_OrderList[7].mName), 1);
	showSoldOut();
}
int CMFCKIOSKDlg::addOrder(int POS) //매뉴 수량 + 1 버튼 처리
{
	if (isInitial(m_OrderList[POS - 1]))
		return 0;
	else {
		m_OrderList[POS - 1].mQty++;
		m_OrderList[POS - 1].mSum = getPrice(m_OrderList[POS - 1].mName) * m_OrderList[POS - 1].mQty; // 구조체 멤버 sum 업데이트

		showOrderList();
	}
	return 0;
}
int CMFCKIOSKDlg::minOrder(int POS) //매뉴 수량 -1 버튼 처리
{
	if (isInitial(m_OrderList[POS - 1]) || m_OrderList[POS -1].mQty == 1)
		return 0;
	else {
		m_OrderList[POS - 1].mQty--;
		m_OrderList[POS - 1].mSum = getPrice(m_OrderList[POS -1].mName) * m_OrderList[POS - 1].mQty; // 구조체 멤버 sum 업데이트
		showOrderList();
	}
	return 0;
}
void CMFCKIOSKDlg::changeSoldout_Img(int pictureControl) // 위치 번호를 받아서 해당하는 위치에 SOLDOUT이미지를 띄워주는 함수
{	
}	

void CMFCKIOSKDlg::showSoldOut()
{
	
}
void CMFCKIOSKDlg::showSoldOut_Image(string mNameStr) //재고가 0개일때 호출되서 해당 매뉴를 품절 표시하는 함수 
{	
}	

string CMFCKIOSKDlg::convertNameString(string str)
{	
		return "Unknown Item";	
}

//Stock map에 quantity만큼 재고 추가 함수 
void CMFCKIOSKDlg::addStock(map<string, int>& Stock, const string& itemName, int quantity) 
{
	Stock[itemName] += quantity;
}

//Stock map에 quantity만큼 재고 제거 함수
void CMFCKIOSKDlg::minStock(map<string, int>& Stock, const string& itemName, int quantity)
{
	Stock[itemName] -= quantity;
}

bool CMFCKIOSKDlg::isSoldOut(map<string, int>& Stock, const string& itemName) {
	// 메뉴 항목이 맵에 있는지 확인하는 함수
	auto it = Stock.find(itemName);
	if (it != Stock.end()) {
		// 메뉴 항목이 맵에 있으면, 재고를 확인
		return it->second == 0;
	}
	else {
		// 메뉴 항목이 맵에 없으면, 기본적으로 판매 중지로 간주할 수 있음
		return true;
	}
}

void CMFCKIOSKDlg::refreshAll_Images() //매뉴 이미지 전체를 새로고침
{
	
}

void CMFCKIOSKDlg::initOrderList_ALL() // 주문 리스트 전체 초기화 함수
{
	initOrder_all(); //구조체 전체 초기화
	refreshOrder();

	showOrderList();

	refreshAll_Images(); //매뉴 이미지 전체 새로고침
	showSoldOut(); // 품절 상품에 SOLDOUTT 이미지 표시 
}


void CMFCKIOSKDlg::OnStnClickedPicturebox1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}