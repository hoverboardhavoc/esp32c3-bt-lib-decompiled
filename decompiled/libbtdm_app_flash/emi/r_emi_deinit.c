/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> emi.o -> r_emi_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_emi_deinit(void)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  
  r_emi_em_base_deinit();
  puVar1 = (uint *)&DAT_60031204;
  iVar2 = 0;
  do {
    if (2 < _g_bt_plf_log_level) {
      puVar3 = puVar1;
      if (0x2f < iVar2) {
        puVar3 = puVar1 + 7;
      }
      ets_printf("EM_BASE_REG[%d], %04x, %08x\n",iVar2,(*puVar3 >> 0x12) << 2,
                 (*puVar3 & 0x3ffff) << 2 | 0x3fc00000);
    }
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 != 0x38);
  return;
}

