
// ImageProcessing_2018108249View.cpp: CImageProcessing2018108249View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageProcessing_2018108249.h"
#endif

#include "ImageProcessing_2018108249Doc.h"
#include "ImageProcessing_2018108249View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProcessing2018108249View

IMPLEMENT_DYNCREATE(CImageProcessing2018108249View, CView)

BEGIN_MESSAGE_MAP(CImageProcessing2018108249View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DOWN_SAMPLING, &CImageProcessing2018108249View::OnDownSampling)
END_MESSAGE_MAP()

// CImageProcessing2018108249View 생성/소멸

CImageProcessing2018108249View::CImageProcessing2018108249View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImageProcessing2018108249View::~CImageProcessing2018108249View()
{
}

BOOL CImageProcessing2018108249View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CImageProcessing2018108249View 그리기

void CImageProcessing2018108249View::OnDraw(CDC* pDC)
{
	CImageProcessing2018108249Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int i, j;
	unsigned char R, G, B;

	for (i = 0; i < pDoc->m_height; i++) {
		for (j = 0; j < pDoc->m_width; j++) {
			R = G = B = pDoc->m_inputimage[i * pDoc->m_width + j];
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}
	}
	
	for (i = 0; i < pDoc->m_Re_height; i++) {
		for (j = 0; j < pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i * pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}
}


// CImageProcessing2018108249View 인쇄

BOOL CImageProcessing2018108249View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImageProcessing2018108249View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImageProcessing2018108249View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CImageProcessing2018108249View 진단

#ifdef _DEBUG
void CImageProcessing2018108249View::AssertValid() const
{
	CView::AssertValid();
}

void CImageProcessing2018108249View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageProcessing2018108249Doc* CImageProcessing2018108249View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcessing2018108249Doc)));
	return (CImageProcessing2018108249Doc*)m_pDocument;
}
#endif //_DEBUG


// CImageProcessing2018108249View 메시지 처리기


void CImageProcessing2018108249View::OnDownSampling()
{
	CImageProcessing2018108249Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnDownSapling();

	Invalidate(TRUE);
}
