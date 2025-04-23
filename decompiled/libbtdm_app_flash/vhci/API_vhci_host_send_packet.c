/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> vhci.o -> API_vhci_host_send_packet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 API_vhci_host_send_packet(char *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = r_sdk_config_get_opts();
  if (*(char *)(iVar1 + 0xc) == '\0') {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = r_sdk_config_get_opts();
    uVar2 = 0xfffffffe;
    if (((*(char *)(iVar1 + 0x17) == '\x01') && (param_1 != (char *)0x0)) && (param_2 != 0)) {
      if (_vhci_env_p != (undefined1 *)0x0) {
        iVar1 = r_vhci_check_packet_allow(param_1,param_2);
        if (iVar1 == 0) {
          return 0xfffffffd;
        }
        (**(code **)(_r_osi_funcs_p + 0x34))
                  (*(undefined4 *)(_vhci_env_p + 4),0xffffffff,*(code **)(_r_osi_funcs_p + 0x34));
        *_vhci_env_p = 1;
        if ((byte)(*param_1 - 1U) < 2) {
          r_hci_tl_save_pkt(param_1,param_2);
          r_btdm_task_post(2,0,0,1);
          return 0;
        }
        r_btdm_task_post(2,0,0,1);
      }
      uVar2 = 0xfffffffb;
    }
  }
  return uVar2;
}

