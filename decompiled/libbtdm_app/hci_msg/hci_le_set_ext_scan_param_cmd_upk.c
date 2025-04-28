/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_msg.o -> hci_le_set_ext_scan_param_cmd_upk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hci_le_set_ext_scan_param_cmd_upk(undefined1 *param_1,int param_2,ushort *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 *puStack_44;
  int iStack_38;
  undefined1 *puStack_34;
  undefined1 auStack_30 [16];
  
  if (param_2 == 0) {
    uVar3 = 0x10;
    iVar2 = 0;
  }
  else {
    bVar1 = param_1 == (undefined1 *)0x0;
    if (bVar1) {
      puStack_44 = &stack0xffffffe0;
      param_1 = auStack_30;
    }
    else {
      puStack_44 = param_1 + *param_3;
    }
    param_4 = param_2 + param_4;
    iStack_38 = param_2;
    puStack_34 = param_1;
    iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                      (&iStack_38,&puStack_34,param_4,puStack_44,1,*(code **)(_r_ip_funcs_p + 0xa4))
    ;
    if (iVar2 == 0) {
      puStack_34 = param_1 + 1;
      iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                        (&iStack_38,&puStack_34,param_4,puStack_44,1,
                         *(code **)(_r_ip_funcs_p + 0xa4));
      if (iVar2 == 0) {
        puStack_34 = param_1 + 2;
        iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                          (&iStack_38,&puStack_34,param_4,puStack_44,1,
                           *(code **)(_r_ip_funcs_p + 0xa4));
        if (iVar2 == 0) {
          uVar5 = 0;
          for (uVar4 = (uint)(byte)param_1[2]; uVar4 != 0; uVar4 = uVar4 >> 1) {
            if ((uVar4 & 1) != 0) {
              uVar5 = uVar5 + 1 & 0xff;
            }
          }
          if (2 < uVar5) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"hci_msg.c",0x719,*(code **)(_r_plf_funcs_p + 8));
          }
          if (bVar1) {
            puStack_44 = (undefined1 *)0x0;
          }
          puVar6 = param_1 + 8;
          for (iVar7 = 0; iVar7 < (int)uVar5; iVar7 = iVar7 + 1) {
            puStack_34 = puVar6 + -4;
            iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                              (&iStack_38,&puStack_34,param_4,puStack_44,1,
                               *(code **)(_r_ip_funcs_p + 0xa4));
            if (iVar2 != 0) goto _L24;
            puStack_34 = puVar6 + -2;
            iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                              (&iStack_38,&puStack_34,param_4,puStack_44,2,
                               *(code **)(_r_ip_funcs_p + 0xa4));
            if (iVar2 != 0) goto _L24;
            puStack_34 = puVar6;
            iVar2 = (**(code **)(_r_ip_funcs_p + 0xa4))
                              (&iStack_38,&puStack_34,param_4,puStack_44,2,
                               *(code **)(_r_ip_funcs_p + 0xa4));
            puVar6 = puVar6 + 6;
            if (iVar2 != 0) goto _L24;
          }
          iVar2 = 0;
        }
      }
    }
_L24:
    uVar3 = (short)puStack_34 - (short)param_1;
  }
  *param_3 = uVar3;
  return iVar2;
}

