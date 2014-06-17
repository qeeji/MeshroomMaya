#pragma once

#include "mayaMVG/core/MVGNodeWrapper.h"
#include "mayaMVG/core/MVGPointCloudItem.h"
#include <openMVG/cameras/PinholeCamera.hpp>
#include <vector>

class MString;
class MFnCamera;

namespace mayaMVG {

class MVGCamera : public MVGNodeWrapper {

	public:
		MVGCamera(const std::string& name);
		MVGCamera(const MDagPath& dagPath);
		MVGCamera(const int& id);
		virtual ~MVGCamera();
	
	public:
		bool operator<(const MVGCamera&) const;

	public:
		virtual bool isValid() const;

	public:
		static MVGCamera create(const std::string& name);
		static std::vector<MVGCamera> list();

	public:
		int id() const;
		void setId(const int&) const;
		MDagPath imagePath() const;
		std::string imagePlane() const;
		void setImagePlane(const std::string&) const;
		void loadImagePlane() const;
		openMVG::PinholeCamera pinholeCamera() const;
		void setPinholeCamera(const openMVG::PinholeCamera&) const;
		std::vector<MVGPointCloudItem> visibleItems() const;
		void setVisibleItems(const std::vector<MVGPointCloudItem>& item) const;
		
		double getZoom() const;
		void setZoom(const double zoom) const;
		double getHorizontalPan() const;
		void setHorizontalPan(const double pan) const;
		double getVerticalPan() const;
		void setVerticalPan(const double pan) const;
		
		std::vector<MPoint> getClickedPoints() const;
		void setClickedPoints(const std::vector<MPoint>& points) const;
		void addClickedPoint(const MPoint& point) const;
		void clearClickedPoints() const;
		MPoint geClickedtPointAtIndex(int i) const;
		void seClickedtPointAtIndex(int i, const MPoint& point) const;
		int getClickedPointsCount() const;
		
	private:
		// MfnCamera _mfnCamera; TODO
		// dynamic attributes
		static MString _ID;
		static MString _PINHOLE;
		static MString _ITEMS;
		static MString _DEFERRED;
		static MString _POINTS;
};

} // mayaMVG
