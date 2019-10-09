
// M_IdleView.cpp: CMIdleView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "M_Idle.h"
#endif

#include "M_IdleDoc.h"
#include "M_IdleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMIdleView

IMPLEMENT_DYNCREATE(CMIdleView, CView)

BEGIN_MESSAGE_MAP(CMIdleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMIdleView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMIdleView 생성/소멸

CMIdleView::CMIdleView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMIdleView::~CMIdleView()
{
}

BOOL CMIdleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMIdleView 그리기

void CMIdleView::OnDraw(CDC* /*pDC*/)
{
	CMIdleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMIdleView 인쇄


void CMIdleView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMIdleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMIdleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMIdleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMIdleView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMIdleView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMIdleView 진단

#ifdef _DEBUG
void CMIdleView::AssertValid() const
{
	CView::AssertValid();
}

void CMIdleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMIdleDoc* CMIdleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMIdleDoc)));
	return (CMIdleDoc*)m_pDocument;
}
#endif //_DEBUG


// CMIdleView 메시지 처리기


void CMIdleView::DrawRect()
{
	CClientDC dc(this);
	RECT r;          // 창의 크기를 저장할 구조체
	GetClientRect(&r); // 창의 크기를 읽어 옴
	int p1, p2, p3;
	p1 = rand() % r.right;    // 오른쪽 제한
	p2 = rand() % r.bottom;  // 아래쪽 제한
	p3 = rand() % 50;       // 사각형의 크기 제한
	dc.Rectangle(p1 - p3, p2 - p3, p1 + p3, p2 + p3);
}
