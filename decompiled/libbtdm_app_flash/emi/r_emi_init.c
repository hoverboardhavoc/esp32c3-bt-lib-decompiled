/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> emi.o -> r_emi_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_emi_init(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  r_emi_em_base_init();
  iVar2 = 0;
  do {
    if (2 < _g_bt_plf_log_level) {
      iVar1 = 0x220;
      if (iVar2 < 0x30) {
        iVar1 = 0x204;
      }
      puVar3 = (uint *)(iVar2 * 4 + iVar1 + 0x60031000);
      ets_printf("EM_BASE_REG[%d], %04x, %08x\n",iVar2,(*puVar3 >> 0x12) << 2,
                 (*puVar3 & 0x3ffff) << 2 | 0x3fc00000);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x38);
  return;
}

