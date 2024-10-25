/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> nvds.o -> r_nvds_browse_tag
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_nvds_browse_tag(uint param_1,byte *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 auStack_24 [3];
  
  auStack_24[0] = 4;
  do {
    uVar1 = auStack_24[0];
    iVar2 = r_nvds_walk_tag(auStack_24[0],param_2,auStack_24);
    if (iVar2 != 0) break;
  } while ((*param_2 != param_1) || ((param_2[1] & 5) != 4));
  *param_3 = uVar1;
  return;
}

