/*
 * Last changed at upstream commit eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * https://github.com/espressif/esp32c3-bt-lib/commit/eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * Upstream date: 2024-10-20 16:32:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(52ee788)
 * Source: libbtdm_app -> llc_con_upd.o -> ll_connection_update_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_connection_update_ind_handler_hack(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x5e8))
                    (*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 6),
                     *(undefined2 *)(param_2 + 8),*(code **)(_r_ip_funcs_p + 0x5e8));
  if (iVar1 == 0) {
    return 0x20;
  }
  uVar4 = (uint)*(ushort *)(param_2 + 4);
  if (uVar4 < *(ushort *)(param_2 + 2)) {
    return 0x20;
  }
  if (*(byte *)(param_2 + 1) == 0) {
    return 0x20;
  }
  iVar1 = 8;
  if (uVar4 < 10) {
    iVar1 = uVar4 - 1;
  }
  if (iVar1 < (int)(uint)*(byte *)(param_2 + 1)) {
    return 0x20;
  }
  if ((*(ushort *)(iVar6 + 0x42) & 1) == 0) {
    if ((param_3 - (uint)*(ushort *)(param_2 + 10) & 0xffff) < 0x7fff) {
      iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(0x20,*(code **)(_r_plf_funcs_p + 0xf0));
      if ((*(byte *)(iVar1 + 0x1d) & 1) != 0) {
        return 0x28;
      }
      if (2 < _g_bt_plf_log_level) {
        ets_printf("con_upd: %u %u %u\n",param_1,param_3,*(undefined2 *)(param_2 + 10));
      }
    }
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,0,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar1 == 5) {
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,0,*(code **)(_r_ip_funcs_p + 0x674));
      uVar2 = 3;
      *(undefined2 *)(iVar1 + 0x28) = *(undefined2 *)(param_2 + 4);
      *(undefined2 *)(iVar1 + 0xc) = *(undefined2 *)(param_2 + 6);
      *(undefined2 *)(iVar1 + 0xe) = *(undefined2 *)(param_2 + 8);
      *(undefined2 *)(iVar1 + 0x24) = *(undefined2 *)(param_2 + 10);
      *(undefined2 *)(iVar1 + 0x22) = *(undefined2 *)(param_2 + 2);
      *(undefined1 *)(iVar1 + 0x26) = *(undefined1 *)(param_2 + 1);
      pcVar5 = *(code **)(_r_ip_funcs_p + 0x5f4);
    }
    else {
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678));
      uVar2 = 9;
      if (iVar1 == 0) {
        puVar3 = (undefined4 *)
                 (**(code **)(_r_modules_funcs_p + 200))
                           (0x10b,1,1,0x30,*(code **)(_r_modules_funcs_p + 200));
        iVar1 = _r_ip_funcs_p;
        *(undefined1 *)(puVar3 + 1) = 5;
        uVar2 = *(undefined4 *)(iVar1 + 0x604);
        pcVar5 = *(code **)(iVar1 + 0x67c);
        *(undefined1 *)((int)puVar3 + 0x2d) = 0;
        *puVar3 = uVar2;
        *(undefined1 *)((int)puVar3 + 0x2e) = 0;
        *(undefined2 *)((int)puVar3 + 0x16) = 0xffff;
        (*pcVar5)(param_1,1,puVar3,pcVar5);
        uVar2 = 7;
      }
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678));
      if (iVar1 != 5) goto _L103;
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,1,*(code **)(_r_ip_funcs_p + 0x674));
      (**(code **)(_r_ip_funcs_p + 0x684))(param_1,uVar2,*(code **)(_r_ip_funcs_p + 0x684));
      *(undefined2 *)(iVar1 + 0x28) = *(undefined2 *)(param_2 + 4);
      *(undefined2 *)(iVar1 + 0xc) = *(undefined2 *)(param_2 + 6);
      *(undefined2 *)(iVar1 + 0xe) = *(undefined2 *)(param_2 + 8);
      *(undefined2 *)(iVar1 + 0x24) = *(undefined2 *)(param_2 + 10);
      *(undefined2 *)(iVar1 + 0x22) = *(undefined2 *)(param_2 + 2);
      *(undefined1 *)(iVar1 + 0x26) = *(undefined1 *)(param_2 + 1);
      *(undefined1 *)(iVar1 + 0x2c) = 1;
      pcVar5 = *(code **)(_r_ip_funcs_p + 0x600);
    }
    (*pcVar5)(param_1,uVar2,0,pcVar5);
    uVar2 = 0;
  }
  else {
_L103:
    uVar2 = 0x24;
  }
  return uVar2;
}

