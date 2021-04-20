/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> vhci.o -> API_vhci_host_send_packet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 API_vhci_host_send_packet(char *param_1,int param_2)

{
  int iVar1;
  
  if (_r_plf_funcs_p != 0) {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(char *)(iVar1 + 0xc) == '\0') {
      return 0xffffffff;
    }
    iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(char *)(iVar1 + 0x17) != '\x01') {
      return 0xfffffffe;
    }
    if (param_1 == (char *)0x0) {
      return 0xfffffffe;
    }
    if (param_2 == 0) {
      return 0xfffffffe;
    }
    if (_vhci_env_p == (undefined1 *)0x0) {
      return 0xfffffffb;
    }
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xd0))(param_1,param_2,*(code **)(_r_plf_funcs_p + 0xd0));
    if (iVar1 == 0) {
      return 0xfffffffd;
    }
    (**(code **)(_r_osi_funcs_p + 0x34))
              (*(undefined4 *)(_vhci_env_p + 4),0xffffffff,*(code **)(_r_osi_funcs_p + 0x34));
    *_vhci_env_p = 1;
    if (1 < (byte)(*param_1 - 1U)) {
      (**(code **)(_r_plf_funcs_p + 0x28))(2,0,0,1,*(code **)(_r_plf_funcs_p + 0x28));
      return 0xfffffffb;
    }
    (**(code **)(_r_ip_funcs_p + 0x58))(param_1,param_2,*(code **)(_r_ip_funcs_p + 0x58));
    (**(code **)(_r_plf_funcs_p + 0x28))(2,0,0,1,*(code **)(_r_plf_funcs_p + 0x28));
  }
  return 0;
}

