/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_hci.o -> lld_acl_rx_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_acl_rx_ind_handler_hack(ushort *param_1,uint param_2)

{
  uint uVar1;
  char cVar2;
  ushort *puVar3;
  int iVar4;
  undefined4 uVar5;
  ushort uVar6;
  int iVar7;
  
  uVar1 = param_2 >> 8;
  iVar7 = *(int *)(&llc_env + uVar1 * 4);
  puVar3 = (ushort *)(**(code **)(_r_ip_funcs_p + 0x910))(*(code **)(_r_ip_funcs_p + 0x910));
  iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((uVar1 < *(byte *)(iVar4 + 0xd)) && (iVar4 = *(int *)(&llc_env + uVar1 * 4), iVar4 != 0)) &&
     ((*(byte *)(iVar4 + 0x44) & 3) != 3)) {
    if (((*(byte *)(iVar7 + 0x44) & 3) == 0) || (((int)(uint)*puVar3 >> (uVar1 & 0x1f) & 1U) != 0))
    {
      puVar3 = (ushort *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1106,uVar1,0,0xc,*(code **)(_r_modules_funcs_p + 200));
      uVar6 = 0x2000;
      if ((char)param_1[5] != '\x02') {
        uVar6 = 0x1000;
      }
      *puVar3 = uVar6 | (ushort)(param_2 >> 8) & 0xfff;
      uVar6 = *param_1;
      puVar3[1] = param_1[4];
      iVar4 = _r_plf_funcs_p;
      puVar3[2] = uVar6;
      uVar5 = (**(code **)(iVar4 + 0xbc))(*(code **)(iVar4 + 0xbc));
      iVar4 = _r_ip_funcs_p;
      *(undefined4 *)(puVar3 + 4) = uVar5;
      (**(code **)(iVar4 + 0x8c))(puVar3,*(code **)(iVar4 + 0x8c));
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if (*(char *)(iVar4 + 0x20) != '\0') {
        (**(code **)(_r_ip_funcs_p + 0x610))(uVar1,*(code **)(_r_ip_funcs_p + 0x610));
      }
      if (ble_acl_data_rx_cb == (code *)0x0) {
        return 0;
      }
      cVar2 = (char)param_1[5];
      if (cVar2 != '\x02') {
        cVar2 = '\x01';
      }
      (*ble_acl_data_rx_cb)(cVar2,*(undefined4 *)(puVar3 + 4),param_1[4]);
      return 0;
    }
    (**(code **)(_r_ip_funcs_p + 0x55c))(uVar1,0x3d,1,*(code **)(_r_ip_funcs_p + 0x55c));
  }
  (**(code **)(_r_ip_funcs_p + 0x104))
            (*param_1,*(undefined4 *)(param_1 + 2),*(code **)(_r_ip_funcs_p + 0x104));
  return 0;
}

