/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
  char cVar3;
  
  iVar1 = r_sdk_config_get_opts();
  if (*(char *)(iVar1 + 0xc) == '\0') {
    r_ble_log_internal_x1(0x80070251,0);
    return 0xffffffff;
  }
  iVar1 = r_sdk_config_get_opts();
  if (*(char *)(iVar1 + 0x17) == '\x01') {
    if ((param_1 != (char *)0x0) && (param_2 != 0)) {
      if (_vhci_env_p == (undefined1 *)0x0) {
        cVar3 = '\0';
        uVar2 = 0x80070254;
      }
      else {
        iVar1 = r_vhci_check_packet_allow(param_1,param_2);
        if (iVar1 == 0) {
          r_ble_log_internal_x1(0x80070255,param_2);
          return 0xfffffffd;
        }
        (**(code **)(_r_osi_funcs_p + 0x34))
                  (*(undefined4 *)(_vhci_env_p + 4),0xffffffff,*(code **)(_r_osi_funcs_p + 0x34));
        *_vhci_env_p = 1;
        cVar3 = *param_1;
        if ((byte)(cVar3 - 1U) < 2) {
          r_hci_tl_save_pkt(param_1,param_2);
          r_btdm_task_post_hack(2,0,0,1);
          return 0;
        }
        r_btdm_task_post_hack(2,0,0,1);
        uVar2 = 0x80070256;
      }
      r_ble_log_internal_x1(uVar2,cVar3);
      return 0xfffffffb;
    }
    r_ble_log_internal_x2(0x80070253,param_1,param_2);
  }
  else {
    iVar1 = r_sdk_config_get_opts();
    r_ble_log_internal_x1(0x80070252,*(undefined1 *)(iVar1 + 0x17));
  }
  return 0xfffffffe;
}

