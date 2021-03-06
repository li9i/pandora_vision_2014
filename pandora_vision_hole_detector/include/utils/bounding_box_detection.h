/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2014, P.A.N.D.O.R.A. Team.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the P.A.N.D.O.R.A. Team nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Alexandros Philotheou, Manos Tsardoulias
 *********************************************************************/

#ifndef UTILS_BOUNDING_BOX_DETECTION_H
#define UTILS_BOUNDING_BOX_DETECTION_H

#include "utils/morphological_operators.h"

/**
  @namespace pandora_vision
  @brief The main namespace for PANDORA vision
 **/
namespace pandora_vision
{
  /**
    @class BoundingBoxDetection
    @brief Provides methods for bounding box detection
   **/
  class BoundingBoxDetection
  {
    public:

      /**
        @brief Finds rotated bounding boxes from blob outlines.
        The blob's area must be larger than
        Parameters::bounding_box_min_area_threshold.
        The blob and its bounding rectangle must be inside the image's limits.
        @param[in] inImage [const cv::Mat&] The input image
        @param[in] blobsOutlineVector
        [const std::vector<std::vector<cv::Point2f> >&]
        The outline points of the blobs
        @param[in] blobsArea [const std::vector<float>&] The blobs' area
        @param[out] outRectangles [std::vector< std::vector<cv::Point2f> >*]
        The rectangles of the bounding boxes
        @return void
       **/
      static void findRotatedBoundingBoxesFromOutline(
        const cv::Mat& inImage,
        const std::vector<std::vector<cv::Point2f> >& blobsOutlineVector,
        const std::vector<float>& blobsArea,
        std::vector< std::vector<cv::Point2f> >* outRectangles);

  };

} // namespace pandora_vision

#endif  // UTILS_BOUNDING_BOX_DETECTION_H
