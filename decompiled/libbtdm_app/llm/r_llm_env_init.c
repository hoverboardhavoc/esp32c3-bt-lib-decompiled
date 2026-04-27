/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llm.o -> r_llm_env_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_llm_env_init(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  
  _p_llm_env = (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0xdc,*(code **)(_r_osi_funcs_p + 0x78));
  if (_p_llm_env != (void *)0x0) {
    memset(_p_llm_env,0,0xdc);
    pcVar4 = *(code **)(_r_osi_funcs_p + 0x78);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    iVar2 = (*pcVar4)((uint)*(byte *)(iVar2 + 0xd) * 0x44);
    if (iVar2 != 0) {
      *(int *)((int)_p_llm_env + 8) = iVar2;
      uVar3 = llm_hci_env_init();
      if (uVar3 != 0) {
        iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
        bVar1 = *(byte *)(iVar2 + 0x23);
        if (bVar1 == 0) {
          return uVar3;
        }
        p_le_scan_duplicate_option =
             (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x3c,*(code **)(_r_osi_funcs_p + 0x78));
        if (p_le_scan_duplicate_option != (void *)0x0) {
          memset(p_le_scan_duplicate_option,0,0x3c);
          return (uint)bVar1;
        }
      }
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x4cc))(*(code **)(_r_ip_funcs_p + 0x4cc));
  return 0;
}

