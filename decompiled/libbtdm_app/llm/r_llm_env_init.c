/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> llm.o -> r_llm_env_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_llm_env_init(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  _p_llm_env = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0xdc,*(code **)(_r_osi_funcs_p + 0x78));
  if (_p_llm_env != (void *)0x0) {
    memset(_p_llm_env,0,0xdc);
    pcVar3 = *(code **)(_r_osi_funcs_p + 0x78);
    iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    iVar1 = (*pcVar3)((uint)*(byte *)(iVar1 + 0xd) * 0x44);
    if (iVar1 != 0) {
      *(int *)((int)_p_llm_env + 8) = iVar1;
      iVar1 = llm_hci_env_init();
      if (iVar1 != 0) {
        iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
        if (*(char *)(iVar2 + 0x23) == '\0') {
          return iVar1;
        }
        p_le_scan_duplicate_option =
             (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x3c,*(code **)(_r_osi_funcs_p + 0x78));
        memset(p_le_scan_duplicate_option,0,0x3c);
        if (p_le_scan_duplicate_option != (void *)0x0) {
          return iVar1;
        }
      }
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x4cc))(*(code **)(_r_ip_funcs_p + 0x4cc));
  return 0;
}

