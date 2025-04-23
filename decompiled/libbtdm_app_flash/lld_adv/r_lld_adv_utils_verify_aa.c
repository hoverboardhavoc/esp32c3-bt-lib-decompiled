/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  uint uVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  
  iVar2 = __popcountsi2((int)param_1 >> 0x1b ^ (int)param_1 >> 0x1a);
  uVar6 = 1;
  if (iVar2 < 2) {
    bVar1 = false;
  }
  else {
    iVar2 = 0x20;
    bVar4 = 0;
    do {
      if ((((param_1 ^ 0x8e89bed6) & uVar6) != 0) && (bVar4 = bVar4 + 1, 1 < bVar4)) goto _L707;
      iVar2 = iVar2 + -1;
      uVar6 = uVar6 << 1;
    } while (iVar2 != 0);
    bVar1 = false;
    if (1 < bVar4) {
_L707:
      bVar4 = 0;
      uVar6 = 1;
      iVar2 = 0x1f;
      bVar5 = 0;
      uVar7 = uVar6;
      do {
        uVar3 = param_1 & uVar7;
        uVar7 = uVar7 << 1;
        if ((param_1 & uVar7) == 0) {
          if (uVar3 != 0) {
            bVar5 = bVar5 + 1;
            uVar6 = 1;
            goto _L693;
          }
          uVar6 = uVar6 + 1 & 0xff;
        }
        else if (uVar3 == 0) {
          bVar5 = bVar5 + 1;
          uVar6 = 1;
        }
        else {
          uVar6 = uVar6 + 1 & 0xff;
_L693:
          bVar4 = bVar4 + 1;
        }
        if (uVar7 == 0x100) {
          if (bVar4 < 3) break;
        }
        else if ((uVar7 == 0x10000) && (0xb < bVar5)) break;
        if (uVar6 == 7) {
          uVar7 = 0;
          break;
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      bVar1 = uVar7 == 0x80000000 && bVar5 < 0x19;
    }
  }
  return bVar1;
}

