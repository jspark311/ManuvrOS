/*
* Taken from Intel's iotivity-constrained package and
*   reworked slightly.
*                                 ---J. Ian Lindsay
*/

/*
// Copyright (c) 2016 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#include "uuid.h"
#include <Platform/Platform.h>

#ifdef __cplusplus
 extern "C" {
#endif


void uuid_from_str(const char *str, UUID *uuid) {
  uint8_t j = 0;
  uint8_t c = 0;
  uint8_t a = 0;

  for (int i = 0; i < strlen(str); i++) {
    switch (str[i]) {
      case 0x30:
      case 0x31:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
      case 0x36:
      case 0x37:
      case 0x38:
      case 0x39:
        c |= ((str[i] - 0x30) << (a++ ? 0 : 4));
        break;
      case 65:
      case 97:
        c |= (a++ ? 0x0a : 0xa0);
        break;
      case 66:
      case 98:
        c |= (a++ ? 0x0b : 0xb0);
        break;
      case 67:
      case 99:
        c |= (a++ ? 0x0c : 0xc0);
        break;
      case 68:
      case 100:
        c |= (a++ ? 0x0d : 0xd0);
        break;
      case 69:
      case 101:
        c |= (a++ ? 0x0e : 0xe0);
        break;
      case 70:
      case 102:
        c |= (a++ ? 0x0f : 0xf0);
        break;
    }

    if (2 <= a) {
      uuid->id[j++] = c;
      if (16 <= j) {
        // If we've written 16 bytes to the UUID, it doesn't
        // matter if there is more string material. It would
        // be unsafe to process it.
        return;
      }
      c = 0;
      a = 0;
    }
  }
}


void uuid_to_str(const UUID* uuid, char *buffer, int buflen) {
  if (buflen < 37) return;
  int j = 0;
  for (int i = 0; i < 16; i++) {
    switch(i) {
      case 4:
      case 6:
      case 8:
      case 10:
        snprintf(&buffer[j], 2, "-");
        j++;
        break;
    }
    snprintf(&buffer[j], 3, "%02x", uuid->id[i]);
    j += 2;
  }
}


void uuid_gen(UUID *uuid) {
  for (int i = 0; i < 4; i++) {
    *((uint32_t*) &uuid->id[i * 4]) = randomInt();
  }

  /*  From RFC 4122
      Set the two most significant bits of the
      clock_seq_hi_and_reserved (8th octect) to
      zero and one, respectively.
  */
  uuid->id[8] = (uuid->id[8] & 0x3f) | 0x40;

  /*  From RFC 4122
      Set the four most significant bits of the
      time_hi_and_version field (6th octect) to the
      4-bit version number from (0 1 0 0 => type 4)
      Section 4.1.3.
  */
  uuid->id[6] = (uuid->id[6] & 0x0f) | 0x40;
}


/*
* Returns 0 if the given UUIDs are the same value.
*/
int uuid_compare(UUID *uuid0, UUID *uuid1) {
  if (*((uint32_t*) &uuid0->id[0]) == *((uint32_t*) &uuid1->id[0])) {
    if (*((uint32_t*) &uuid0->id[4]) == *((uint32_t*) &uuid1->id[4])) {
      if (*((uint32_t*) &uuid0->id[8]) == *((uint32_t*) &uuid1->id[8])) {
        if (*((uint32_t*) &uuid0->id[12]) == *((uint32_t*) &uuid1->id[12])) {
          return 0;
        }
      }
    }
  }
  return 1;
}


void uuid_copy(UUID* src, UUID* dest) {
  *((uint32_t*) &dest->id[0])  = *((uint32_t*) &src->id[0]);
  *((uint32_t*) &dest->id[4])  = *((uint32_t*) &src->id[4]);
  *((uint32_t*) &dest->id[8])  = *((uint32_t*) &src->id[8]);
  *((uint32_t*) &dest->id[12]) = *((uint32_t*) &src->id[12]);
}


#ifdef __cplusplus
}
#endif
