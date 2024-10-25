/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_le_ping.o -> f_llc_auth_payl_real_to_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_llc_auth_payl_real_to_handler(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  
  uVar1 = param_1 >> 8;
  iVar4 = *(int *)(&llc_env + uVar1 * 4);
  iVar2 = r_sdk_config_get_opts();
  if (((((uVar1 & 0xff) < (uint)*(byte *)(iVar2 + 0xd)) &&
       (iVar2 = *(int *)(&llc_env + uVar1 * 4), iVar2 != 0)) && ((*(byte *)(iVar2 + 0x44) & 3) != 3)
      ) && ((*(ushort *)(iVar4 + 0x42) & 0x20) != 0)) {
    puVar3 = (undefined2 *)r_ke_msg_alloc(0x1103,uVar1,0x57,2);
    *puVar3 = (short)(param_1 >> 8);
    r_hci_send_2_host();
    r_llc_le_ping_restart(uVar1 & 0xff);
  }
  return 0;
}

