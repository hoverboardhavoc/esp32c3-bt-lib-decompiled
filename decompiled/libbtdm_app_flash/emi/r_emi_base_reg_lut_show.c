/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> emi.o -> r_emi_base_reg_lut_show
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_emi_base_reg_lut_show(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = &em_base_reg_lut;
  iVar2 = 0;
  do {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("EM_BASE_REG_LUT[%d], %02d, %04x\n",iVar2,*puVar1,*(undefined2 *)(puVar1 + 2));
    }
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 4;
  } while (iVar2 != 0x33);
  return;
}

