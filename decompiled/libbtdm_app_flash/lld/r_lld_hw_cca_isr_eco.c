/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_hw_cca_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_hw_cca_isr_eco(char param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = r_sdk_config_get_opts_ext();
  iVar1 = _p_lld_env;
  if (*(char *)(iVar2 + 0x19) != '\x02') {
    iVar2 = *(int *)(_p_lld_env + 0x114);
    *(char *)(_p_lld_env + 0x104) = param_1;
    *(char *)(iVar1 + 0x105) = (char)param_2;
    *(undefined1 *)(iVar2 + param_2) = param_3;
    r_ke_event_set(0xe);
    return;
  }
  r_lld_cca_hw_handle((int)param_1);
  return;
}

