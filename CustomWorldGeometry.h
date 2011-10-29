// CustomWorldGeometry.h: interface for the CustomWorldGeometry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CUSTOMWORLDGEOMETRY_H__1AE61AB6_30D3_408B_B4EF_723C156E2AAA__INCLUDED_)
#define AFX_CUSTOMWORLDGEOMETRY_H__1AE61AB6_30D3_408B_B4EF_723C156E2AAA__INCLUDED_

#include <acgi.h>

class CustomWorldDraw;

class CustomWorldGeometry: public AcGiWorldGeometry
{ 

public:
    ACRX_DECLARE_MEMBERS(CustomWorldGeometry);
	CustomWorldGeometry(CustomWorldDraw* pWorldDraw);
	~CustomWorldGeometry();

    virtual void getModelToWorldTransform(AcGeMatrix3d &pMatrix) const;
    virtual void getWorldToModelTransform(AcGeMatrix3d &pMatrix) const;
    virtual void setExtents(AcGePoint3d *pNewExtents) const;

    virtual Adesk::Boolean  circle(const AcGePoint3d& center,
				const double radius,
				const AcGeVector3d& normal
				) const;

    virtual Adesk::Boolean  circle(const AcGePoint3d& pt1,
				const AcGePoint3d& pt2,
				const AcGePoint3d& pt3
				) const;

    virtual Adesk::Boolean  circularArc(const AcGePoint3d& center,
				const double radius,
				const AcGeVector3d& normal,
				const AcGeVector3d& startVector,
				const double sweepAngle,
				const AcGiArcType arcType = kAcGiArcSimple
				) const;

    virtual Adesk::Boolean  circularArc(const AcGePoint3d& start,
				const AcGePoint3d& point,
				const AcGePoint3d& end,
				const AcGiArcType arcType = kAcGiArcSimple
				) const;
      
    virtual Adesk::Boolean  polyline(const Adesk::UInt32 nbPoints,
                   const AcGePoint3d* pVertexList,
				   const AcGeVector3d* pNormal = NULL,
				   Adesk::Int32 lBaseSubEntMarker = -1) const;
      
    virtual Adesk::Boolean  polygon(const Adesk::UInt32 nbPoints,
				const AcGePoint3d* pVertexList
				) const;

    virtual Adesk::Boolean  mesh(const Adesk::UInt32 rows,
				const Adesk::UInt32 columns,
				const AcGePoint3d* pVertexList,
				const AcGiEdgeData* pEdgeData = NULL,
				const AcGiFaceData* pFaceData = NULL,
				const AcGiVertexData* pVertexData = NULL
				) const;

    virtual Adesk::Boolean  shell(const Adesk::UInt32 nbVertex,
                                 const AcGePoint3d* pVertexList,
                                 const Adesk::UInt32 faceListSize,
                                 const Adesk::Int32* pFaceList,
                                 const AcGiEdgeData* pEdgeData = NULL,
                                 const AcGiFaceData* pFaceData = NULL,
                                 const AcGiVertexData* pVertexData = NULL,
                                 const struct resbuf* pResBuf = NULL
                                 ) const;
 
      
    virtual Adesk::Boolean  text(const AcGePoint3d& position,
				const AcGeVector3d& normal,
				const AcGeVector3d& direction,
				const double height,
				const double width,
				const double oblique,
				const char* pMsg
				) const;

    virtual Adesk::Boolean  text(const AcGePoint3d& position,
				const AcGeVector3d& normal,
				const AcGeVector3d& direction,
				const char* pMsg,
				const Adesk::Int32 length,
				const Adesk::Boolean raw,
				const AcGiTextStyle &pTextStyle
				) const;

    virtual Adesk::Boolean  xline(const AcGePoint3d& one_xline_point,
				const AcGePoint3d& a_different_xline_point
				) const;

    virtual Adesk::Boolean  ray(const AcGePoint3d& rays_starting_point,
				const AcGePoint3d& a_different_ray_point
				) const;
    virtual Adesk::Boolean  pline(const AcDbPolyline& lwBuf,
                                  Adesk::UInt32 fromIndex = 0,
                                  Adesk::UInt32 numSegs = 0
                                  ) const;

    virtual Adesk::Boolean pushModelTransform(const AcGeVector3d & vNormal);// Uses arbitrary Axis algorythm
    virtual Adesk::Boolean pushModelTransform(const AcGeMatrix3d & xMat);
    virtual Adesk::Boolean popModelTransform();

	virtual Adesk::Boolean  draw(AcGiDrawable*) const;
    // If you push a clip boundary onto the stack you must pop it;
    virtual Adesk::Boolean  pushClipBoundary(AcGiClipBoundary * pBoundary);
    /*NEW*/virtual void     popClipBoundary();

private:
	CustomWorldDraw*	mpCustomWorldDraw;
	// Back pointer stored to the WorldDraw object.  This class
	// uses it to store the ShellData when the shell member
	// function is called.
};

/*
{
public:
#ifdef CAD2000
	virtual Adesk::Boolean draw(AcGiDrawable*) const {return 0;}
	
	// If you push a clip boundary onto the stack you must pop it;
	//
	virtual Adesk::Boolean pushClipBoundary(AcGiClipBoundary * pBoundary) {return 0;};
	virtual void popClipBoundary() {}
	
	virtual Adesk::Boolean pushModelTransform(const AcGeVector3d & vNormal) {return 0;}// Uses arbitrary Axis algorythm
	virtual Adesk::Boolean pushModelTransform(const AcGeMatrix3d & xMat) {return 0;}
	virtual Adesk::Boolean popModelTransform() {return 0;}
	virtual Adesk::Boolean polyline(const Adesk::UInt32 nbPoints,
		const AcGePoint3d* pVertexList,
		const AcGeVector3d* pNormal = NULL,
		Adesk::Int32 lBaseSubEntMarker = -1) const {return 0;}
#endif CAD2000
	
public:
	ACRX_DECLARE_MEMBERS(CustomWorldGeometry);
	CustomWorldGeometry(CustomWorldDraw* pWorldDraw);
	~CustomWorldGeometry();
	
	virtual void getModelToWorldTransform(AcGeMatrix3d &pMatrix) const;
	virtual void getWorldToModelTransform(AcGeMatrix3d &pMatrix) const;
	virtual void setExtents(AcGePoint3d *pNewExtents) const;
	
	virtual Adesk::Boolean circle(const AcGePoint3d& center,
		const double radius,
		const AcGeVector3d& normal
		) const;
	
	virtual Adesk::Boolean circle(const AcGePoint3d& pt1,
		const AcGePoint3d& pt2,
		const AcGePoint3d& pt3
		) const;
	
	virtual Adesk::Boolean circularArc(const AcGePoint3d& center,
		const double radius,
		const AcGeVector3d& normal,
		const AcGeVector3d& startVector,
		const double sweepAngle,
		const AcGiArcType arcType = kAcGiArcSimple
		) const;
	
	virtual Adesk::Boolean circularArc(const AcGePoint3d& start,
		const AcGePoint3d& point,
		const AcGePoint3d& end,
		const AcGiArcType arcType = kAcGiArcSimple
		) const;
	
	virtual Adesk::Boolean polyline(const Adesk::UInt32 nbPoints,
		const AcGePoint3d* pVertexList,
		const AcGeVector3d* pNormal = NULL) const;
	
	virtual Adesk::Boolean polygon(const Adesk::UInt32 nbPoints,
		const AcGePoint3d* pVertexList
		) const;
	
	virtual Adesk::Boolean mesh(const Adesk::UInt32 rows,
		const Adesk::UInt32 columns,
		const AcGePoint3d* pVertexList,
		const AcGiEdgeData* pEdgeData = NULL,
		const AcGiFaceData* pFaceData = NULL,
		const AcGiVertexData* pVertexData = NULL
		) const;
	
	virtual Adesk::Boolean shell(const Adesk::UInt32 nbVertex,
		const AcGePoint3d* pVertexList,
		const Adesk::UInt32 faceListSize,
		const Adesk::Int32* pFaceList,
		const AcGiEdgeData* pEdgeData = NULL,
		const AcGiFaceData* pFaceData = NULL,
		const AcGiVertexData* pVertexData = NULL,
		const struct resbuf* pResBuf = NULL
		) const;
	
	
	virtual Adesk::Boolean text(const AcGePoint3d& position,
		const AcGeVector3d& normal,
		const AcGeVector3d& direction,
		const double height,
		const double width,
		const double oblique,
		const char* pMsg
		) const;
	
	virtual Adesk::Boolean text(const AcGePoint3d& position,
		const AcGeVector3d& normal,
		const AcGeVector3d& direction,
		const char* pMsg,
		const Adesk::Int32 length,
		const Adesk::Boolean raw,
		const AcGiTextStyle &pTextStyle
		) const;
	
	virtual Adesk::Boolean xline(const AcGePoint3d& one_xline_point,
		const AcGePoint3d& a_different_xline_point
		) const;
	
	virtual Adesk::Boolean ray(const AcGePoint3d& rays_starting_point,
		const AcGePoint3d& a_different_ray_point
		) const;
	virtual Adesk::Boolean pline(const AcDbPolyline& lwBuf,
		Adesk::UInt32 fromIndex = 0,
		Adesk::UInt32 numSegs = 0
		) const;
	
	
private:
	CustomWorldDraw * mpCustomWorldDraw;
	// Back pointer stored to the WorldDraw object. This class
	// uses it to store the ShellData when the shell member
	// function is called.
};
*/
#endif // !defined(AFX_CUSTOMWORLDGEOMETRY_H__1AE61AB6_30D3_408B_B4EF_723C156E2AAA__INCLUDED_)
