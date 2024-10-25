/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> hci_le_rem_con_param_req_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_rem_con_param_req_reply_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  ushort uVar3;
  
  iVar1 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar1 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    iVar1 = r_llc_con_upd_param_in_range
                      (param_1,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),
                       *(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8));
    uVar2 = 0x20;
    if (iVar1 == 0) goto _L271;
    iVar1 = r_llc_proc_get(param_1,1,0x20);
    if (iVar1 != 0) {
      uVar3 = *(ushort *)(iVar1 + 10);
      if (*(ushort *)(iVar1 + 10) < *(ushort *)(param_2 + 4)) {
        uVar3 = *(ushort *)(param_2 + 4);
      }
      *(ushort *)(iVar1 + 10) = uVar3;
      uVar3 = *(ushort *)(iVar1 + 8);
      if (*(ushort *)(iVar1 + 8) < *(ushort *)(param_2 + 2)) {
        uVar3 = *(ushort *)(param_2 + 2);
      }
      *(ushort *)(iVar1 + 8) = uVar3;
      uVar3 = *(ushort *)(iVar1 + 0xe);
      if (*(ushort *)(iVar1 + 0xe) < *(ushort *)(param_2 + 8)) {
        uVar3 = *(ushort *)(param_2 + 8);
      }
      *(ushort *)(iVar1 + 0xe) = uVar3;
      r_llc_rem_con_upd_proc_continue(param_1,8,0);
      uVar2 = 0;
      goto _L271;
    }
  }
  uVar2 = 0xc;
_L271:
  r_llc_cmd_cmp_send(param_1,param_3,uVar2);
  return 0;
}

