/*
 * Last changed at upstream commit b438f60a295183e7c67eb42ae05f4580f4b1ced0
 * https://github.com/espressif/esp32c3-bt-lib/commit/b438f60a295183e7c67eb42ae05f4580f4b1ced0
 * Upstream date: 2023-06-12 21:42:40 +0800
 * Upstream subject: update libbtdm_app.a for ESP32C3 and ESP32S3(963cad48)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  bVar1 = *(byte *)(_lld_scan_env + 0xd);
  iVar9 = *(int *)(param_1 * 4 + _lld_scan_env);
  while (uVar5 = (**(code **)(_r_ip_funcs_p + 0x2a4))
                           (*(undefined1 *)(iVar9 + 0x38),*(code **)(_r_ip_funcs_p + 0x2a4)),
        uVar5 != 0) {
    uVar11 = (uint)*(byte *)(_p_lld_env + 0xd8);
    (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar6 = uVar11 * 0x14;
    if (*(ushort *)(iVar9 + 0x36) < 0x673) {
      iVar10 = iVar6 + 4;
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = *(ushort *)(iVar7 + iVar6 + 2);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      if ((*(ushort *)(iVar7 + iVar10) & 0xf) < 7) {
        bVar2 = *(byte *)(_lld_scan_env + 0x17);
        if (bVar2 != 0) {
          lld_ext_scan_dynamic_pti_reset(iVar9);
          uVar5 = (uint)bVar2;
        }
      }
      else {
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = *(ushort *)(iVar6 + 0x10 + iVar7);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar5 = (uint)((uVar3 & 0x3f) < *(ushort *)(iVar6 + iVar10) >> 8);
      }
      if (((uVar4 & 0x602d) == 0) && (uVar5 != 0)) {
        uStack_44 = 0xff;
        *(undefined1 *)(iVar9 + 0x43) = 1;
        uStack_4c = 0;
        uStack_48 = 0;
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar4 = *(ushort *)(iVar6 + iVar10) & 0xf;
        if (((*(ushort *)(iVar6 + iVar10) & 8) != 0) || ((uVar4 - 3 & 0xfd) == 0)) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x22e,*(code **)(_r_plf_funcs_p + 8));
        }
        if (uVar4 < 7) {
          pcVar8 = *(code **)(_r_ip_funcs_p + 0x420);
        }
        else {
          pcVar8 = *(code **)(_r_ip_funcs_p + 0x40c);
        }
        (*pcVar8)(param_1,uVar4,uVar11,&uStack_4c,pcVar8);
        (**(code **)(_r_ip_funcs_p + 0x424))
                  (param_1,uVar4,uVar11,&uStack_4c,*(code **)(_r_ip_funcs_p + 0x424));
      }
      else if ((_DAT_60031048 & 8) != 0) {
        (**(code **)(_r_ip_funcs_p + 0x428))(param_1,*(code **)(_r_ip_funcs_p + 0x428));
        if (*(char *)(_lld_scan_env + 0x17) != '\0') {
          lld_ext_scan_dynamic_pti_reset(iVar9);
        }
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar9 = ((uint)bVar1 * 9 & 0xff) * 0xe;
  if (*(short *)(iVar6 + iVar9) < 0) {
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = *(ushort *)(iVar6 + iVar9);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar6 + iVar9) = uVar4 & 0x7fff;
  }
  return;
}

