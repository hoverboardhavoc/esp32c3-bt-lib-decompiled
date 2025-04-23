/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_env_adv_dup_filt_init_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_env_adv_dup_filt_init_eco(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    if (*(int *)(_p_llm_env + 0xcc) == 0) {
      return 1;
    }
    r_assert_err(0,"llm_scan.c",0x64e);
    return 1;
  }
  if (*(int *)(_p_llm_env + 0xcc) == 0) {
    iVar4 = r_sdk_config_get_opts();
    iVar3 = _r_osi_funcs_p;
    iVar2 = _p_llm_env;
    bVar1 = *(byte *)(iVar4 + 0x12);
    *(byte *)(_p_llm_env + 0xd0) = bVar1;
    uVar5 = (**(code **)(iVar3 + 0x74))((uint)bVar1 * 0xe,*(code **)(iVar3 + 0x74));
    iVar3 = _p_llm_env;
    *(undefined4 *)(iVar2 + 0xcc) = uVar5;
    if (*(int *)(iVar3 + 0xcc) == 0) {
      *(undefined1 *)(iVar3 + 0xd0) = 0;
      if (1 < _g_bt_plf_log_level) {
        ets_printf("LLM Scan dup filt init failed!\n");
      }
      return 0;
    }
  }
  return 1;
}

