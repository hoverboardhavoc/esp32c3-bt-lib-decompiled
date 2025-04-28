/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> emi.o -> r_emi_em_base_deinit
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
    puVar4 = puVar6 + 7;
    if ((int)uVar1 < 0x30) {
      puVar4 = puVar6;
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
        r_assert_warn(uVar1,uVar5,0x10000,0x5b);
      }
      (**(code **)(_r_osi_funcs_p + 0x7c))
                (uVar5 << 2 | 0x3fc00000,*(code **)(_r_osi_funcs_p + 0x7c));
      if ((int)uVar1 < 0x20) {
        puVar4 = (uint *)&DAT_600312c4;
        uVar2 = _DAT_600312c4;
        uVar5 = uVar1;
      }
      else if ((int)uVar1 < 0x30) {
        puVar4 = (uint *)&DAT_600312c8;
        uVar5 = uVar1 - 0x20;
        uVar2 = _DAT_600312c8;
      }
      else {
        puVar4 = (uint *)&DAT_60031300;
        uVar5 = uVar1 - 0x30;
        uVar2 = _DAT_60031300;
      }
      *puVar4 = ~(1 << (uVar5 & 0x1f)) & uVar2;
    }
    uVar1 = uVar1 + 1;
    puVar6 = puVar6 + 1;
  } while (uVar1 != 0x38);
  return;
}

