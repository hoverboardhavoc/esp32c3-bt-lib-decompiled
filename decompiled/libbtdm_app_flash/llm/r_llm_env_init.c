/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_env_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_llm_env_init(void)

{
  code *pcVar1;
  int iVar2;
  
  _p_llm_env = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0xdc,*(code **)(_r_osi_funcs_p + 0x78));
  if (_p_llm_env != (void *)0x0) {
    memset(_p_llm_env,0,0xdc);
    pcVar1 = *(code **)(_r_osi_funcs_p + 0x78);
    iVar2 = r_sdk_config_get_opts();
    iVar2 = (*pcVar1)((uint)*(byte *)(iVar2 + 0xd) * 0x44);
    if (iVar2 != 0) {
      *(int *)((int)_p_llm_env + 8) = iVar2;
      iVar2 = llm_hci_env_init();
      if (iVar2 != 0) {
        return iVar2;
      }
    }
  }
  r_llm_env_deinit();
  return 0;
}

