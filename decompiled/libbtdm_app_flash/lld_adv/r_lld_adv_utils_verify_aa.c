/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_utils_verify_aa
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool r_lld_adv_utils_verify_aa(uint param_1)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  
  iVar2 = __popcountsi2((int)param_1 >> 0x1b ^ (int)param_1 >> 0x1a);
  if (1 < iVar2) {
    iVar2 = 0x20;
    bVar1 = false;
    uVar4 = 1;
    do {
      if (((param_1 ^ 0x8e89bed6) & uVar4) != 0) {
        if (bVar1) {
          iVar2 = 0x1f;
          bVar3 = 0;
          bVar5 = 0;
          uVar4 = 1;
          bVar6 = 1;
          goto _L715;
        }
        bVar1 = true;
      }
      iVar2 = iVar2 + -1;
      uVar4 = uVar4 << 1;
    } while (iVar2 != 0);
  }
  return false;
_L715:
  uVar8 = param_1 & uVar4;
  uVar4 = uVar4 << 1;
  bVar7 = 1;
  if ((param_1 & uVar4) == 0) {
    if (uVar8 != 0) {
      bVar5 = bVar5 + 1;
      goto _L720;
    }
    bVar7 = bVar6 + 1;
  }
  else if (uVar8 == 0) {
    bVar5 = bVar5 + 1;
  }
  else {
    bVar7 = bVar6 + 1;
_L720:
    bVar3 = bVar3 + 1;
  }
  if (uVar4 == 0x100) {
    if (bVar3 < 3) {
      return false;
    }
  }
  else if ((uVar4 == 0x10000) && (0xb < bVar5)) {
    return false;
  }
  if (6 < bVar7) {
    return false;
  }
  iVar2 = iVar2 + -1;
  bVar6 = bVar7;
  if (iVar2 == 0) {
    return uVar4 == 0x80000000 && bVar5 < 0x19;
  }
  goto _L715;
}

