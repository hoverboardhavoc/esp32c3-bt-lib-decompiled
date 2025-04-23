/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  ushort *puVar4;
  int iVar5;
  undefined4 uVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  
  uVar8 = param_2 >> 8;
  iVar9 = *(int *)(&llc_env + uVar8 * 4);
  puVar4 = (ushort *)(**(code **)(_r_ip_funcs_p + 0x910))(*(code **)(_r_ip_funcs_p + 0x910));
  iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((uVar8 < *(byte *)(iVar5 + 0xd)) && (iVar5 = *(int *)(&llc_env + uVar8 * 4), iVar5 != 0)) &&
     ((*(byte *)(iVar5 + 0x44) & 3) != 3)) {
    if (((*(byte *)(iVar9 + 0x44) & 3) == 0) || (((int)(uint)*puVar4 >> (uVar8 & 0x1f) & 1U) != 0))
    {
      puVar4 = (ushort *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1106,uVar8,0,0xc,*(code **)(_r_modules_funcs_p + 200));
      uVar7 = 0x1000;
      if ((char)param_1[5] == '\x02') {
        uVar7 = 0x2000;
      }
      uVar1 = param_1[4];
      uVar2 = *param_1;
      *puVar4 = (ushort)(param_2 >> 8) | uVar7;
      puVar4[1] = uVar1;
      iVar5 = _r_plf_funcs_p;
      puVar4[2] = uVar2;
      uVar6 = (**(code **)(iVar5 + 0xbc))(*(code **)(iVar5 + 0xbc));
      iVar5 = _r_ip_funcs_p;
      *(undefined4 *)(puVar4 + 4) = uVar6;
      (**(code **)(iVar5 + 0x8c))(puVar4,*(code **)(iVar5 + 0x8c));
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if (*(char *)(iVar5 + 0x20) != '\0') {
        (**(code **)(_r_ip_funcs_p + 0x610))(uVar8,*(code **)(_r_ip_funcs_p + 0x610));
      }
      if (ble_acl_data_rx_cb == (code *)0x0) {
        return 0;
      }
      cVar3 = (char)param_1[5];
      if (cVar3 != '\x02') {
        cVar3 = '\x01';
      }
      (*ble_acl_data_rx_cb)(cVar3,*(undefined4 *)(puVar4 + 4),param_1[4]);
      return 0;
    }
    (**(code **)(_r_ip_funcs_p + 0x55c))(uVar8,0x3d,1,*(code **)(_r_ip_funcs_p + 0x55c));
  }
  (**(code **)(_r_ip_funcs_p + 0x104))
            (*param_1,*(undefined4 *)(param_1 + 2),*(code **)(_r_ip_funcs_p + 0x104));
  return 0;
}

