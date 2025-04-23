/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> emi.o -> r_emi_em_base_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_emi_em_base_deinit(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  
  puVar6 = (uint *)&DAT_60031204;
  uVar1 = 0;
  do {
    puVar4 = puVar6;
    if (0x2f < (int)uVar1) {
      puVar4 = puVar6 + 7;
    }
    uVar5 = *puVar4 & 0x3ffff;
    if (uVar5 != 0) {
      uVar2 = _DAT_600312c4;
      uVar3 = uVar1;
      if (0x1f < (int)uVar1) {
        if ((int)uVar1 < 0x30) {
          uVar2 = _DAT_600312c8;
          uVar3 = uVar1 - 0x20;
        }
        else {
          uVar2 = _DAT_60031300;
          uVar3 = uVar1 - 0x30;
        }
      }
      if (((1 << (uVar3 & 0x1f) & uVar2) >> (uVar3 & 0x1f) & 0xff) == 0) {
        (**(code **)(_r_plf_funcs_p + 0x10))
                  (uVar1,uVar5,0x10000,0x5b,*(code **)(_r_plf_funcs_p + 0x10));
      }
      (**(code **)(_r_osi_funcs_p + 0x7c))
                (uVar5 << 2 | 0x3fc00000,*(code **)(_r_osi_funcs_p + 0x7c));
      if ((int)uVar1 < 0x20) {
        puVar4 = (uint *)&DAT_600312c4;
        uVar2 = _DAT_600312c4;
        uVar5 = uVar1;
      }
      else {
        if (0x2f < (int)uVar1) {
          _DAT_60031300 = ~(1 << (uVar1 - 0x30 & 0x1f)) & _DAT_60031300;
          goto _L3;
        }
        puVar4 = (uint *)&DAT_600312c8;
        uVar5 = uVar1 - 0x20;
        uVar2 = _DAT_600312c8;
      }
      *puVar4 = ~(1 << (uVar5 & 0x1f)) & uVar2;
    }
_L3:
    uVar1 = uVar1 + 1;
    puVar6 = puVar6 + 1;
    if (uVar1 == 0x38) {
      return;
    }
  } while( true );
}

