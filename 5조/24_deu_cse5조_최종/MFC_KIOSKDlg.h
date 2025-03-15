
// MFC_KIOSKDlg.h: 헤더 파일
//

#pragma once
#include "Modal_Pay.h"

// headers about database connection
#include <afxdb.h>
#include <odbcinst.h>
#include <sqlext.h>


#include <map>
#include <string>
#include <iterator>
using namespace std;
//
// CMFCKIOSKDlg 대화 상자
class CMFCKIOSKDlg : public CDialogEx
{
	// 생성입니다.
public:
	CMFCKIOSKDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.


	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_KIOSK_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


	// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();
public:
	CBitmap m_myBackground;
	// 배경 이미지 멤버변수

//	afx_msg void OnBnClickedButton2();
	
	void m_setButtonPositiion(int buttonX, int buttonY, int nID);
	//afx_msg void OnStnClickedPicturebox3();
	CFont m_font_menu; // 매뉴 텍스트 폰트를 저장하기 위한 멤버변수
	CFont m_font_price; // 매뉴 텍스트 폰트를 저장하기 위한 멤버변수
	CFont m_font_order; // 주문 텍스트 폰트를 저장하기 위한 멤버변수
	CFont m_font_editbox; //에디트박스 텍스트 폰트를 저장 
	CFont m_font_ordersum; // 가격 총합 텍스트 폰트를 저장
	CFont m_font_allsum;
	CFont m_font_order_amount; // 주문 수량 조절 텍스트 폰트를 저장하기 위한 멤버변수

	void m_setFont_for_m_font_menu(int nID); // 매뉴 텍스트 폰트를 변경하기 위한 멤버함수
	void m_setFont_for_m_font_price(int nID); //매뉴 가격 텍스트 폰트를 변경하기 위한 멤버함수
	void m_setFont_for_m_font_order(int nID); //
	void m_setFont_for_m_font_ordersum(int nID); //
	void m_setFont_for_m_font_edit(int nID); //
	void m_setFont_for_m_font_allsum(int nID); //

	//void m_setFont2(CFont font, int nID); //사용하지 않는 함수!!!!!!!!

	void m_setFont_menu(int fontsize, int FW);
	void m_setFont_price(int fontsize, int FW);
	void m_setFont_editbox(int fontsize, int FW);
	void m_setFont_order(int fontsize, int FW);
	void m_setFont_ordersum(int fontsize, int FW);
	void m_setFont_allsum(int fontsize, int FW);
	void m_setFont_order_amount(int fontsize, int FW);

	afx_msg void OnClickedButtonCoffee();
	afx_msg void OnClickedButtonCraft();
	afx_msg void OnClickedButtonTea();
	afx_msg void OnClickedButtonBread();
	afx_msg void OnClickedButtonUp();
	afx_msg void OnClickedButtonDown();
	void ClickedCoffeeUp();
	void ClickedCoffeeDown();
	void ClickedCraftUp();
	void ClickedTeaUp();
	void ClickedBreadUp();
	void ClickedBreadDown();
	CStatic m_Text1;
	CStatic m_Text2;
	CStatic m_Text3;
	CStatic m_Text4;
	CStatic m_Text5;
	CStatic m_Text6;
	CStatic m_Text7;
	CStatic m_Text8;
	CStatic m_Text9;
	CStatic m_Price1;
	CStatic m_Price2;
	CStatic m_Price3;
	CStatic m_Price4;
	CStatic m_Price5;
	CStatic m_Price6;
	CStatic m_Price7;
	CStatic m_Price8;
	CStatic m_Price9;
	bool m_buttonCoffee;
	bool m_buttonBread;
	bool m_buttonTea;
	bool m_buttonCraft;
	bool m_buttonBreadDown;
	bool m_buttonCoffeeDown;
	bool m_buttonCraftDown;
	bool m_buttonTeaDown;
	bool m_korean;
	bool m_english;
	bool m_chinese;
	afx_msg void OnClickedButtonKorean();
//	afx_msg void OnClickedButtonEnglish();
//	afx_msg void OnClickedButtonChinese();
	void ClearTextFields();
	CStatic m_pictureControl1;
	CStatic m_pictureControl2;
	CStatic m_pictureControl3;
	CStatic m_pictureControl4;
	CStatic m_pictureControl5;
	CStatic m_pictureControl6;
	CStatic m_pictureControl7;
	CStatic m_pictureControl8;
	CStatic m_pictureControl9;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//RECT r1 = (x시작, y시작, x끝, y끝 좌표}
	RECT r1 = { 129, 370, 1150, 1100 };    //메뉴판 이미지 범위
	RECT r2 = { 1262, 130, 1900, 660 };    //order 큐 범위(변경 필요할수 있음)
	CStatic m_textOrder1;
	CStatic m_textOrderSum1;
	CStatic m_textOrderSum2;
	CStatic m_textOrderSum3;
	CStatic m_textOrderSum4;
	CStatic m_textOrderSum5;
	CStatic m_textOrderSum6;
	CStatic m_textOrderSum7;
	CStatic m_textOrderSum8;
	CStatic m_textOrder2;
	CStatic m_textOrder3;
	CStatic m_textOrder4;
	CStatic m_textOrder5;
	CStatic m_textOrder6;
	CStatic m_textOrder7;
	CStatic m_textOrder8;
	CEdit m_edit1;
	CEdit m_edit2;
	CEdit m_edit3;
	CEdit m_edit4;
	CEdit m_edit5;
	CEdit m_edit6;
	CEdit m_edit7;
	CEdit m_edit8;
	


	afx_msg void OnClickedButtonHere();
	afx_msg void OnClickedButtonTogo();
	Modal_Pay m_dlgPay;
	void ClickedCraftDown();
	void ClickedTeaDown();

	afx_msg void OnStnClickedTextOrder1();
	void m_setFont_order_amount(int);
	afx_msg void OnStnClickedTextOrder14();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnStnClickedTextOrder13();
	afx_msg void OnStnClickedTextOrder3Sum();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnStnClickedTextOrder18();
	afx_msg void OnStnClickedTextOrder12();
	CStatic m_orderlist_1;
	CStatic m_orderlist_2;
	CStatic m_orderlist_3;
	CStatic m_orderlist_4;
	CStatic m_orderlist_5;
	CStatic m_orderlist_6;
	CStatic m_orderlist_7;
	CStatic m_orderlist_8;
	CStatic m_orderlist14;
	CStatic m_orderlist14_2;
	afx_msg void OnStnClickedTextOrder19();
	
	void Add_List(int);



	CDatabase db; // CDatabase db;
	CRecordset rs; // CRecordSet rs;

	int Tno; // 거래(영수증)번호
	CString ymd; // yy_mm_dd
	CString t1name;
	CString t2name;

	//주문 리스트 구조체 ( 앱 내부용 )
	struct OrderList {
	int mName = 0; //매뉴명 
	int mQty = 0; // 수량 
	int mSum = 0; // 메뉴당 가격 총합
	};

	//주문 리스트 구조체 배열 선언
	//구조체 초기화
	struct OrderList m_OrderList[8]; // 주문 리스트 구조체 배열 선언

	//주문 리스트 구조체 삽입 함수 
	int InsertOrder(int);

	//매뉴 이름 enum
	enum Menu{
	밀키스 = 1,
	마운틴_듀,
	프렌치_카페,
	코카콜라_제로,
	환타_오렌지,
	스프라이트,
	사과에이드,
	스타벅스_카페라떼,
	썬업_오렌지,
	물,
	티니핑_음료수,
	육개장_작은컵,
	신라면_투움바,
	신라면_블랙,
	마열라면,
	진라면_매운맛,
	불닭볶음면,
	라면사리,
	진라면_순한맛,
	참깨라면_볶음면,
	삼양라면,
	콕찍어소시지,
	떡하니붙어라,
	압도적_돈가스파스타,
	짜파게티_순살찜닭,
	고기많이_도시락,
	소불고기_마파덮밥,
	콘칲,
	고래밥,
	꼬북칩,
	오사쯔,
	새우깡,
	};
	
	//////////////////////////////////////////////////////////////////////////////////
							//앱 내부 재고 정보를 저장하는 map
	//////////////////////////////////////////////////////////////////////////////////
	std::map<std::string, int> Stock = { 
	{"밀키스", -1},
	{"마운틴_듀", -1},
	{"프렌치_카페", -1},
	{"코카콜라_제로", -1},
	{"환타_오렌지", -1},
	{"스프라이트", -1},
	{"사과에이드", -1},
	{"스타벅스_카페라떼", -1},
	{"썬업_오렌지", -1},
	{"물", -1},
	{"티니핑_음료수", -1},
	{"육개장_작은컵", -1},
	{"신라면_투움바", -1},
	{"신라면_블랙", -1},
	{"마열라면", -1},
	{"진라면_매운맛", -1},
	{"불닭볶음면", -1},
	{"라면사리", -1},
	{"진라면_순한맛", -1},
	{"참깨라면_볶음면", -1},
	{"삼양라면", -1},
	{"콕찍어소시지", -1},
	{"떡하니붙어라", -1},
	{"압도적_돈가스파스타", -1},
	{"짜파게티_순살찜닭", -1},
	{"고기많이_도시락", -1},
	{"소불고기_마파덮밥", -1},
	{"콘칲", -1},
	{"고래밥", -1},
	{"꼬북칩", -1},
	{"오사쯔", -1},
	{"새우깡", -1}
	};
	//////////////////////////////////////////////////////////////////////////////////


	bool isInitial(struct OrderList);
	int getPrice(int item_number);
	int deleteOrder(int p_order);
	int initOrder_one(int);
	int initOrder_all();
	int showOrderList();
	char* getName(int name);
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedCanc1();
	afx_msg void OnBnClickedCanc2();
	afx_msg void OnBnClickedCanc3();
	afx_msg void OnBnClickedCanc4();
	afx_msg void OnBnClickedCanc5();
	afx_msg void OnBnClickedCanc6();
	afx_msg void OnBnClickedCanc7();
	afx_msg void OnBnClickedCanc8();
	void refreshOrder();
	void setTextInit(int nID);
	afx_msg void OnStnClickedTextOrder2Sum();
	afx_msg void OnStnClickedTextOrder8Sum();
	afx_msg void OnStnClickedletf1();
	afx_msg void OnStnClickedletf2();
	afx_msg void OnStnClickedletf3();
	afx_msg void OnStnClickedletf4();
	afx_msg void OnStnClickedletf5();
	afx_msg void OnStnClickedletf6();
	afx_msg void OnStnClickedletf7();
	afx_msg void OnStnClickedletf8();
	afx_msg void OnStnClickedright1();
	afx_msg void OnStnClickedright2();
	afx_msg void OnStnClickedright3();
	afx_msg void OnStnClickedright4();
	afx_msg void OnStnClickedright5();
	afx_msg void OnStnClickedright6();
	afx_msg void OnStnClickedright7();
	afx_msg void OnStnClickedright8();
	int addOrder(int POS);
	int minOrder(int POS);
	CStatic m_ALLSUM;
	int sumPrice;
	bool m_isBreadDown = false;
	

	CImage image;
	void changeSoldout_Img(int);
	
	
	void showSoldOut();
	void showSoldOut_Image(string mNameStr);
	string convertNameString(string str);
	void addStock(std::map<std::string, int>& inventory, const std::string& itemName, int quantity); // 재고에 quantity만큼 추가
	void minStock(map<string, int>& Stock, const string& itemName, int quantity); // 재고에 quantity만큼 제거

	bool isSoldOut(map<string, int>& Stock, const string& itemName); // itemName의 재고가 0개인지 확인하는 함수


	void refreshAll_Images();

	bool m_Flag_SOLDOUT;
	void initOrderList_ALL();

	void initDB(void);
	void restoreStock(void);
	void restoreTno(void);

	bool buy(void);
	afx_msg void OnStnClickedPicturebox1();
};