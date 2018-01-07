/*
Copyright (c) 2018, TeleCommunication Systems, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
   * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the TeleCommunication Systems, Inc., nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
DISCLAIMED. IN NO EVENT SHALL TELECOMMUNICATION SYSTEMS, INC.BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * (C) Copyright 2012 by TeleCommunication Systems, Inc.
 *
 * The information contained herein is confidential, proprietary
 * to TeleCommunication Systems, Inc., and considered a trade secret
 * as defined in section 499C of the penal code of the State of
 * California. Use of this information by anyone other than
 * authorized employees of TeleCommunication Systems is granted only
 * under a written non-disclosure agreement, expressly prescribing
 * the scope and manner of such use.
 *
 */

// This is a wrapper class to provide high level access to low level 
// link and node iterators.

#ifndef _LINKNODEITERATOR_
#define _LINKNODEITERATOR_

#include "Segment.h"

class CLinkIterator;
class CNodeIterator;
class MapNode;
class MapLink;
class Map;

#define LINKNODEITERATOR_VER    3

namespace Ncdb {

class Session;

class NCDB_API CLinkNodeIterator
{
public:
    CLinkNodeIterator(Session&  session);
    ~CLinkNodeIterator();

    void InitLinkIterator (float lonMin, float latMin, float lonMax, float latMax);
    const NodeSegmentID * GetNextLink();
    bool IsEdgeLink () const;
    bool IsLongLink () const;

    void InitNodeIterator (float lonMin, float latMin, float lonMax, float latMax);
    const Node * GetNextNode();
    const RoadSegmentIDList * GetLinksAtNode();

    void GetMapBBox (Ncdb::WorldRect & rect) const;
    bool GetOriginalMapBBox (int mapId, Ncdb::WorldRect & rect) const;

    int GetNumMaps () const;
    void GetMapID (const WorldPoint & wp, AutoArray<int> & mapIdList);

    void Reset();

private:
    Session &           m_session;
    Map *               m_pMap;
    int                 m_shpMode;
    CLinkIterator *     m_linkIterator;
    CNodeIterator *     m_nodeIterator;

    MapLink *           m_mapLink;
    NodeSegmentID       m_seg;

    Node                m_node;
    MapNode *           m_mapNode;
    RoadSegmentIDList   m_segList;
};

};

#endif //_LINKNODEITERATOR_