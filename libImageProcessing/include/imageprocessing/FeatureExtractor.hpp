/*
 * FeatureExtractor.hpp
 *
 *  Created on: 19.02.2013
 *      Author: poschmann
 */

#ifndef FEATUREEXTRACTOR_HPP_
#define FEATUREEXTRACTOR_HPP_

#include "opencv2/core/core.hpp"
#include <memory>

using cv::Mat;
using std::shared_ptr;

namespace imageprocessing {

class VersionedImage;
class Patch;

/**
 * Feature extractor that constructs a feature vector given an image and a rectangular size specifying a patch.
 */
class FeatureExtractor {
public:

	virtual ~FeatureExtractor() {}

	/**
	 * Forces an update of this feature extractor, so subsequent extracted features are based on the new image.
	 *
	 * @param[in] image The new source image of extracted patches.
	 */
	virtual void update(const Mat& image) = 0;

	/**
	 * May update this feature extractor depending on the version number of the given image. If updated, the
	 * subsequent extracted features are based on the new image.
	 *
	 * @param[in] image The new source image of extracted patches.
	 */
	virtual void update(shared_ptr<VersionedImage> image) = 0;

	/**
	 * Extracts the feature vector at a certain location (patch) of the current image.
	 *
	 * @param[in] x The x-coordinate of the center position of the patch.
	 * @param[in] y The y-coordinate of the center position of the patch.
	 * @param[in] width The width of the patch.
	 * @param[in] height The height of the patch.
	 * @return A pointer to the patch (with its feature vector) that might be empty if the patch could not be created.
	 */
	virtual shared_ptr<Patch> extract(int x, int y, int width, int height) const = 0;
};

} /* namespace imageprocessing */
#endif /* FEATUREEXTRACTOR_HPP_ */
