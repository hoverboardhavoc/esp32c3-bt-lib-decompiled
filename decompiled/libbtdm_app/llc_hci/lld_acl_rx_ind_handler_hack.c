/*
 * Last changed at upstream commit f45e6918026b6e8fdc6dec3f626a98c35960f50e
 * https://github.com/espressif/esp32c3-bt-lib/commit/f45e6918026b6e8fdc6dec3f626a98c35960f50e
 * Upstream date: 2021-06-21 17:00:22 +0530
 * Upstream subject: Fix MIC error issue during start_encryption procedure Update ESP32C3 and ESP32S3 libraries (a86af1e)
 * Source: libbtdm_app -> llc_hci.o -> lld_acl_rx_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_acl_rx_ind_handler_hack(ushort *param_1,uint param_2)

{
  int iVar1;
  ushort *puVar2;
  undefined4 uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar5 = param_2 >> 8;
  iVar7 = *(int *)(&llc_env + uVar5 * 4);
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar6 = uVar5 & 0xff;
  if (((uVar6 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + uVar5 * 4), iVar1 != 0)) &&
     ((*(byte *)(iVar1 + 0x44) & 3) != 3)) {
    if (((*(byte *)(iVar7 + 0x44) & 3) == 0) ||
       (((int)(uint)enc_resp_recvd_slave >> (uVar5 & 0x1f) & 1U) != 0)) {
      puVar2 = (ushort *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1106,uVar5,0,0xc,*(code **)(_r_modules_funcs_p + 200));
      uVar4 = 0x2000;
      if ((char)param_1[5] != '\x02') {
        uVar4 = 0x1000;
      }
      *puVar2 = (ushort)(param_2 >> 8) & 0xfff | uVar4;
      uVar4 = *param_1;
      puVar2[1] = param_1[4];
      iVar1 = _r_plf_funcs_p;
      puVar2[2] = uVar4;
      uVar3 = (**(code **)(iVar1 + 0xbc))(*(code **)(iVar1 + 0xbc));
      iVar1 = _r_ip_funcs_p;
      *(undefined4 *)(puVar2 + 4) = uVar3;
      (**(code **)(iVar1 + 0x8c))(puVar2,*(code **)(iVar1 + 0x8c));
      (**(code **)(_r_ip_funcs_p + 0x610))(uVar6,*(code **)(_r_ip_funcs_p + 0x610));
      return 0;
    }
    (**(code **)(_r_ip_funcs_p + 0x55c))(uVar6,0x3d,1,*(code **)(_r_ip_funcs_p + 0x55c));
  }
  (**(code **)(_r_ip_funcs_p + 0x104))
            (*param_1,*(undefined4 *)(param_1 + 2),*(code **)(_r_ip_funcs_p + 0x104));
  return 0;
}

