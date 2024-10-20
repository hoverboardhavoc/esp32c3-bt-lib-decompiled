/*
 * Last changed at upstream commit eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * https://github.com/espressif/esp32c3-bt-lib/commit/eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * Upstream date: 2024-10-20 16:32:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(52ee788)
 * Source: libbtdm_app -> llc_chmap_upd.o -> ll_channel_map_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_channel_map_ind_handler_hack(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) &&
     (iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(1,*(code **)(_r_ip_funcs_p + 0x678)), iVar1 == 0)
     ) {
    uVar2 = (**(code **)(_r_modules_funcs_p + 0xc))
                      ((void *)(param_2 + 1),*(code **)(_r_modules_funcs_p + 0xc));
    if ((uVar2 < 2) || ((*(byte *)(param_2 + 5) & 0xe0) != 0)) {
      uVar4 = 0x20;
    }
    else {
      if ((param_3 - (uint)*(ushort *)(param_2 + 6) & 0xffff) < 0x7fff) {
        iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
        if ((*(byte *)(iVar1 + 0x1d) & 2) != 0) {
          return 0x28;
        }
        if (2 < _g_bt_plf_log_level) {
          ets_printf("chm_upd: %u %u %u\n",param_1,param_3,*(undefined2 *)(param_2 + 6));
        }
      }
      puVar3 = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x10d,param_1 << 8 | 1,0x10,*(code **)(_r_modules_funcs_p + 200));
      *(undefined1 *)(puVar3 + 1) = 6;
      (**(code **)(_r_ip_funcs_p + 0x684))(param_1,3,*(code **)(_r_ip_funcs_p + 0x684));
      iVar1 = _r_ip_funcs_p;
      *puVar3 = *(undefined4 *)(_r_ip_funcs_p + 0x618);
      memcpy(puVar3 + 2,(void *)(param_2 + 1),5);
      *(undefined2 *)((int)puVar3 + 0xe) = *(undefined2 *)(param_2 + 6);
      (**(code **)(iVar1 + 0x67c))(param_1,1,puVar3,*(code **)(iVar1 + 0x67c));
      (**(code **)(_r_ip_funcs_p + 0x620))(param_1,3,0,*(code **)(_r_ip_funcs_p + 0x620));
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0x24;
  }
  return uVar4;
}

