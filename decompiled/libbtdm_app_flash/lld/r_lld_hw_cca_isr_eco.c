/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
    *(char *)(_p_lld_env + 0x104) = param_1;
    *(char *)(iVar1 + 0x105) = (char)param_2;
    *(undefined1 *)(*(int *)(iVar1 + 0x114) + param_2) = param_3;
    r_ke_event_set(0xe);
    return;
  }
  r_lld_cca_hw_handle((int)param_1);
  return;
}

