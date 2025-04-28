/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> emi.o -> r_emi_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_emi_init(void)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  
  r_emi_em_base_init();
  puVar1 = (uint *)&DAT_60031204;
  iVar2 = 0;
  do {
    if (2 < _g_bt_plf_log_level) {
      puVar3 = puVar1 + 7;
      if (iVar2 < 0x30) {
        puVar3 = puVar1;
      }
      ets_printf("EM_BASE_REG[%d], %04x, %08x\n",iVar2,(*puVar3 >> 0x12) << 2,
                 (*puVar3 & 0x3ffff) << 2 | 0x3fc00000);
    }
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 != 0x38);
  return;
}

