/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_hci.o -> lld_acl_rx_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_acl_rx_ind_handler_hack(ushort *param_1,uint param_2)

{
  char cVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar6 = param_2 >> 8;
  iVar8 = *(int *)(&llc_env + uVar6 * 4);
  puVar2 = (ushort *)(**(code **)(_r_ip_funcs_p + 0x910))(*(code **)(_r_ip_funcs_p + 0x910));
  uVar7 = uVar6 & 0xff;
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((uVar7 < *(byte *)(iVar3 + 0xd)) && (iVar3 = *(int *)(&llc_env + uVar6 * 4), iVar3 != 0)) &&
     ((*(byte *)(iVar3 + 0x44) & 3) != 3)) {
    if (((*(byte *)(iVar8 + 0x44) & 3) == 0) || (((int)(uint)*puVar2 >> (uVar6 & 0x1f) & 1U) != 0))
    {
      puVar2 = (ushort *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1106,uVar6,0,0xc,*(code **)(_r_modules_funcs_p + 200));
      uVar5 = 0x2000;
      if ((char)param_1[5] != '\x02') {
        uVar5 = 0x1000;
      }
      *puVar2 = (ushort)(param_2 >> 8) & 0xfff | uVar5;
      uVar5 = *param_1;
      puVar2[1] = param_1[4];
      iVar3 = _r_plf_funcs_p;
      puVar2[2] = uVar5;
      uVar4 = (**(code **)(iVar3 + 0xbc))(*(code **)(iVar3 + 0xbc));
      iVar3 = _r_ip_funcs_p;
      *(undefined4 *)(puVar2 + 4) = uVar4;
      (**(code **)(iVar3 + 0x8c))(puVar2,*(code **)(iVar3 + 0x8c));
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if (*(char *)(iVar3 + 0x20) != '\0') {
        (**(code **)(_r_ip_funcs_p + 0x610))(uVar7,*(code **)(_r_ip_funcs_p + 0x610));
      }
      if (ble_acl_data_rx_cb == (code *)0x0) {
        return 0;
      }
      cVar1 = (char)param_1[5];
      if (cVar1 != '\x02') {
        cVar1 = '\x01';
      }
      (*ble_acl_data_rx_cb)(cVar1,*(undefined4 *)(puVar2 + 4),param_1[4]);
      return 0;
    }
    (**(code **)(_r_ip_funcs_p + 0x55c))(uVar7,0x3d,1,*(code **)(_r_ip_funcs_p + 0x55c));
  }
  (**(code **)(_r_ip_funcs_p + 0x104))
            (*param_1,*(undefined4 *)(param_1 + 2),*(code **)(_r_ip_funcs_p + 0x104));
  return 0;
}

