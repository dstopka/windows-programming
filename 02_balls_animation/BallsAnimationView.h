#pragma once

class CMyBallsAnimationView : public CView
{
protected: // create from serialization only
	CMyBallsAnimationView();
	DECLARE_DYNCREATE(CMyBallsAnimationView)

// Attributes
public:
	CMyBallsAnimationDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMyBallsAnimationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBallAdd();
	afx_msg void OnBallDelete();
	afx_msg void OnAnimationStart();
	afx_msg void OnAnimationStop();
	afx_msg void OnStartStop();
	afx_msg void OnUpdateAnimationStart( CCmdUI *pCmdUI );
	afx_msg void OnUpdateAnimationStop( CCmdUI *pCmdUI );

public:
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg void OnTimer( UINT_PTR nIDEvent );
	afx_msg BOOL OnEraseBkgnd( CDC* pDC );
	virtual void OnPrepareDC( CDC* pDC, CPrintInfo* pInfo = NULL );
	afx_msg void OnSize( UINT nType, int cx, int cy );

private:
	bool isAnimation_;
	CMyBallsAnimationDoc* document_;
	UINT_PTR timerID_;
	std::shared_ptr<CRect> clientRect_;
};

#ifndef _DEBUG  // debug version in BallsAnimation.cpp
inline CMyBallsAnimationDoc* CMyBallsAnimationView::GetDocument() const
   { return reinterpret_cast<CMyBallsAnimationDoc*>(m_pDocument); }
#endif

