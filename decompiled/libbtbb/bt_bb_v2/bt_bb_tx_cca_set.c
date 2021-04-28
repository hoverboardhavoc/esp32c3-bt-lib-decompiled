/*
 * Last changed at upstream commit 2c453f09b7d1102ef496278d2cd2be96ff1ea071
 * https://github.com/espressif/esp32c3-bt-lib/commit/2c453f09b7d1102ef496278d2cd2be96ff1ea071
 * Upstream date: 2021-04-28 17:55:23 +0800
 * Upstream subject: update ESP32C3/ESP32S3 libbtbb.a
 * Source: libbtbb -> bt_bb_v2.o -> bt_bb_tx_cca_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_bb_tx_cca_set(int param_1,uint param_2,int param_3,uint param_4,uint param_5,int param_6,
                     uint param_7,int param_8)

{
  uint uVar1;
  uint uVar2;
  uint in_stack_00000000;
  uint in_stack_00000004;
  
  if (param_1 == 0) {
    _DAT_600110b8 = _DAT_600110b8 & 0x7fffffff;
  }
  else {
    _DAT_600110b8 = _DAT_600110b8 | 0x80000000;
  }
  _DAT_600110b8 = (param_2 & 0xff) << 1 | _DAT_600110b8 & 0xfffffe01 | 1;
  if (param_3 == 0) {
    _DAT_600110bc = _DAT_600110bc & 0xbfffffff;
  }
  else {
    _DAT_600110bc = _DAT_600110bc | 0x40000000;
  }
  uVar1 = (param_4 & 0xf) << 0x1a;
  uVar2 = (param_5 & 0xf) << 0x16;
  if (param_6 == 0) {
    uVar2 = uVar2 | uVar1 | _DAT_600110bc & 0xc01fffff;
  }
  else {
    uVar2 = uVar2 | uVar1 | _DAT_600110bc & 0xc03fffff | 0x200000;
  }
  uVar1 = (param_7 & 0xff) << 0xd;
  if (param_8 == 0) {
    uVar1 = uVar1 | uVar2 & 0xffe00fff;
  }
  else {
    uVar1 = uVar1 | uVar2 & 0xffe01fff | 0x1000;
  }
  _DAT_600110bc =
       (in_stack_00000004 & 0xf) << 4 | (in_stack_00000000 & 0xf) << 8 | uVar1 & 0xfffff00f |
       0x80000000;
  return;
}

