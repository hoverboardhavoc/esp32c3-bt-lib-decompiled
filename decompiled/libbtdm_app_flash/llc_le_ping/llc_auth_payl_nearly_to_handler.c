/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_le_ping.o -> llc_auth_payl_nearly_to_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
llc_auth_payl_nearly_to_handler
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x20) == '\0') {
    return 0;
  }
  uVar1 = param_3 >> 8 & 0xff;
  iVar4 = *(int *)(&llc_env + (param_3 >> 8) * 4);
  iVar3 = r_sdk_config_get_opts(param_1,param_2,param_4);
  if ((((uVar1 < *(byte *)(iVar3 + 0xd)) &&
       (iVar3 = *(int *)(&llc_env + (param_3 >> 8) * 4), iVar3 != 0)) &&
      ((*(byte *)(iVar3 + 0x44) & 3) != 3)) && ((*(ushort *)(iVar4 + 0x42) & 0x20) != 0)) {
    puVar2 = (undefined4 *)r_ke_msg_alloc(0x10c,param_3,8);
    *(undefined1 *)(puVar2 + 1) = 8;
    r_llc_proc_state_set(uVar1,0);
    *puVar2 = r_llc_le_ping_proc_err_cb;
    r_ke_msg_send(puVar2);
  }
  return 0;
}

