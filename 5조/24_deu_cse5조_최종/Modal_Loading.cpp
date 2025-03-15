// Modal_Loading.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_KIOSK.h"
#include "afxdialogex.h"
#include "Modal_Loading.h"
#include "flag.h"

// Modal_Loading 대화 상자

IMPLEMENT_DYNAMIC(Modal_Loading, CDialogEx)

Modal_Loading::Modal_Loading(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG_LOADING, pParent), m_nTimer(0)
{
}

Modal_Loading::~Modal_Loading()
{
}

void Modal_Loading::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}
// Modal_Loading.cpp 파일의 OnInitDialog 함수 내에 해당 코드를 추가합니다.
BOOL Modal_Loading::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    CenterWindow();

    // IDC_STATIC_PAYING 컨트롤에 "결제중입니다"라는 텍스트를 출력합니다.
    CWnd* pWnd = GetDlgItem(IDC_STATIC_PAYING);
    if (pWnd != nullptr) {
        pWnd->SetWindowText(_T("결제중입니다"));
    }

    // 타이머를 0.1초 간격으로 설정
    m_nTimer = SetTimer(1, 500, nullptr); // 0.1초마다 onTimer 함수 실행

    // 3초 후에 창을 닫기 위해 타이머 설정
    SetTimer(2, 3000, nullptr); // 3초 후에 onTimerClose 함수 실행

    flag_pay_done = true;
    dotCount = 0; // 점 개수 초기화
    return TRUE;
}

void Modal_Loading::OnTimer(UINT_PTR nIDEvent)
{
    if (nIDEvent == 1) {
        // 현재 텍스트 가져오기
        CString strText;
        CWnd* pWnd = GetDlgItem(IDC_STATIC_PAYING);
        if (pWnd != nullptr) {
            pWnd->GetWindowText(strText);
        }

        // 최대 3개의 점만 추가
        if (dotCount < 3) {
            strText += _T(".");
            dotCount++;
        }
        else {
            // 3개 이상이면 점 초기화 후 추가
            strText = _T("결제중입니다");
            strText += _T(".");
            dotCount = 1;
        }

        pWnd->SetWindowText(strText);
    }
    else if (nIDEvent == 2) {
        // 3초 후에 창을 닫음
        KillTimer(m_nTimer); // 텍스트 변경 타이머 종료
        DestroyWindow();
    }

    CDialogEx::OnTimer(nIDEvent);
}

BEGIN_MESSAGE_MAP(Modal_Loading, CDialogEx)
    ON_WM_TIMER()
END_MESSAGE_MAP()
