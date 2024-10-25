/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_hci.o -> hci_vs_set_pref_slave_latency_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_vs_set_pref_slave_latency_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = r_sdk_config_get_opts();
  uVar2 = 0xc;
  if (param_1 < *(byte *)(iVar1 + 0xd)) {
    uVar2 = 0xc;
    if (*(int *)(&llc_env + param_1 * 4) != 0) {
      if ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3) {
        r_lld_con_pref_slave_latency_set(param_1,*(undefined2 *)(param_2 + 2),0xc);
        uVar2 = 0;
      }
    }
  }
  r_llc_cmd_cmp_send(param_1,param_3,uVar2);
  return 0;
}

