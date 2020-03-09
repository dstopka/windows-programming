
// 01_sort_timeDoc.h : interface of the CMy01_sort_timeDoc class
//


#pragma once
#include "Chart.h"

class CMy01_sort_timeDoc : public CDocument
{
protected: // create from serialization only
	CMy01_sort_timeDoc();
	DECLARE_DYNCREATE(CMy01_sort_timeDoc)

// Attributes
public:
	Chart& getChart();
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMy01_sort_timeDoc();
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

private:
	Chart chart_;
};
