/*
File:   SensorDatum.cpp
Author: J. Ian Lindsay
Date:   2016.12.23

Copyright 2016 Manuvr, Inc

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/


#include "SensorWrapper.h"


SensorDatum::SensorDatum(const DatumDef* d) : Argument(d->type_id) {
  def = d;
  _flags = def->flgs & SENSE_DATUM_FLAG_PRELOAD_MASK;
  setKey(d->desc);

  if (len) {
    target_mem = malloc(len);
    if (target_mem) {
      memset(target_mem, 0x00, len);
      _flags |= SENSE_DATUM_FLAG_MEM_ALLOC;
    }
  }
}


SensorDatum::~SensorDatum() {
  // Memory freeing semantics are encapsulated in Argument class.
}


void SensorDatum::autoreport(SensorReporting ar) {
  switch (ar) {
    case SensorReporting::OFF:
      break;
    case SensorReporting::EVERY_READ:
      reportAll();
      break;
    case SensorReporting::NEW_VALUE:
      reportChanges();
      break;
  }
}


SensorError SensorDatum::printValue(StringBuilder* output) {
  Argument::valToString(output);
  if (def->units) output->concat(def->units);
  return SensorError::NO_ERROR;
}


void SensorDatum::printDebug(StringBuilder* output) {
  Argument::printDebug(output);
}
