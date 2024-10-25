/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_env_adv_dup_filt_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_env_adv_dup_filt_init(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
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
      if (_g_bt_plf_log_level < 2) {
        return 0;
      }
      ets_printf("LLM Scan dup filt init failed!\n");
      return 0;
    }
  }
  return 1;
}

