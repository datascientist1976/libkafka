//////////////////////////////////////////////////////////////////
//                                                              //
// libkafka - C/C++ client for Apache Kafka v0.8+               //
//                                                              //
// David Tompkins -- 8/8/2013                                   //
// http://dt.org/                                               //
//                                                              //
// Copyright (c) 2013 by David Tompkins.                        //
//                                                              //
//////////////////////////////////////////////////////////////////
//                                                              //
// This program is free software; you can redistribute it       //
// and/or modify it under the terms of the GNU General Public   //
// License as published by the Free Software Foundation.        //
//                                                              //
// This program is distributed in the hope that it will be      //
// useful, but WITHOUT ANY WARRANTY; without even the implied   //
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR      //
// PURPOSE. See the GNU General Public License for more details //
//                                                              //
// You should have received a copy of the GNU General Public    //
// License along with this program; if not, write to the Free   //
// Software Foundation, Inc., 59 Temple Place, Suite 330,       //
// Boston, MA 02111-1307 USA                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef FETCHPARTITION_H
#define FETCHPARTITION_H

#include <string>
#include "../Debug.h"
#include "../Packet.h"
#include "../WireFormatter.h"
#include "../PacketWriter.h"

namespace LibKafka {

class FetchPartition : public WireFormatter, public PacketWriter
{
  public:

    int partition;
    long int fetchOffset;
    int maxBytes;

    FetchPartition(Packet *packet);
    FetchPartition(int partition, long int fetchOffset, int maxBytes);
    ~FetchPartition();

    unsigned char* toWireFormat(bool updatePacketSize = true);
    int getWireFormatSize(bool includePacketSize = false);
};

std::ostream& operator<< (std::ostream& os, const FetchPartition& fp);
inline bool operator==(const FetchPartition& lhs, const FetchPartition& rhs) { return ((lhs.partition==rhs.partition)&&(lhs.fetchOffset==rhs.fetchOffset)&&(lhs.maxBytes==rhs.maxBytes)); }
inline bool operator!=(const FetchPartition& lhs, const FetchPartition& rhs) { return !operator==(lhs,rhs); }

}; // namespace LibKafka

#endif /* FETCHPARTITION_H */
