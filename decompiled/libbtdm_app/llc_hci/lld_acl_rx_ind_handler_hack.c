/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llc_hci.o -> lld_acl_rx_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_acl_rx_ind_handler_hack(ushort *param_1,uint param_2)

{
  ushort *puVar1;
  int iVar2;
  undefined4 uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar5 = param_2 >> 8;
  iVar7 = *(int *)(&llc_env + uVar5 * 4);
  puVar1 = (ushort *)(**(code **)(_r_ip_funcs_p + 0x910))(*(code **)(_r_ip_funcs_p + 0x910));
  uVar6 = uVar5 & 0xff;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((uVar6 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + uVar5 * 4), iVar2 != 0)) &&
     ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    if (((*(byte *)(iVar7 + 0x44) & 3) == 0) || (((int)(uint)*puVar1 >> (uVar5 & 0x1f) & 1U) != 0))
    {
      puVar1 = (ushort *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1106,uVar5,0,0xc,*(code **)(_r_modules_funcs_p + 200));
      uVar4 = 0x2000;
      if ((char)param_1[5] != '\x02') {
        uVar4 = 0x1000;
      }
      *puVar1 = (ushort)(param_2 >> 8) & 0xfff | uVar4;
      uVar4 = *param_1;
      puVar1[1] = param_1[4];
      iVar2 = _r_plf_funcs_p;
      puVar1[2] = uVar4;
      uVar3 = (**(code **)(iVar2 + 0xbc))(*(code **)(iVar2 + 0xbc));
      iVar2 = _r_ip_funcs_p;
      *(undefined4 *)(puVar1 + 4) = uVar3;
      (**(code **)(iVar2 + 0x8c))(puVar1,*(code **)(iVar2 + 0x8c));
      (**(code **)(_r_ip_funcs_p + 0x610))(uVar6,*(code **)(_r_ip_funcs_p + 0x610));
      return 0;
    }
    (**(code **)(_r_ip_funcs_p + 0x55c))(uVar6,0x3d,1,*(code **)(_r_ip_funcs_p + 0x55c));
  }
  (**(code **)(_r_ip_funcs_p + 0x104))
            (*param_1,*(undefined4 *)(param_1 + 2),*(code **)(_r_ip_funcs_p + 0x104));
  return 0;
}

