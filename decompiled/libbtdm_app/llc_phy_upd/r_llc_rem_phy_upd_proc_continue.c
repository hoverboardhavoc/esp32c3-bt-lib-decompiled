/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_phy_upd.o -> r_llc_rem_phy_upd_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_phy_upd_proc_continue(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  byte bVar9;
  undefined1 uVar10;
  code *pcVar11;
  int iVar12;
  
  iVar12 = *(int *)(&llc_env + param_1 * 4);
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x674))(1,*(code **)(_r_ip_funcs_p + 0x674));
  uVar1 = *(undefined1 *)(iVar12 + 0x1c);
  uVar2 = *(undefined1 *)(iVar12 + 0x1d);
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x7e8))
                    (1,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x7e8));
  if (iVar5 != 0) {
    return;
  }
  iVar5 = param_3;
  if (param_3 == 0) {
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar4,*(code **)(_r_ip_funcs_p + 0x680));
    if (iVar6 != param_2) {
      pcVar11 = *(code **)(_r_plf_funcs_p + 0x10);
      (**(code **)(_r_ip_funcs_p + 0x680))(iVar4);
      (*pcVar11)(param_2,"llc_phy_upd.c",0x26e);
      goto _L27;
    }
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar4);
    if (iVar6 == 6) {
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,0,*(code **)(_r_ip_funcs_p + 0x68c));
      if (*(short *)(iVar4 + 0xc) == 0) {
        pcVar11 = *(code **)(_r_ip_funcs_p + 0x3cc);
        goto _L44;
      }
      if (*(byte *)(iVar4 + 0xd) == 0) {
        bVar9 = *(byte *)(iVar12 + 0x1c);
      }
      else {
        bVar9 = (&co_phy_mask_to_value)[*(byte *)(iVar4 + 0xd)];
      }
      uVar10 = (&co_phy_to_rate)[bVar9];
      if ((bVar9 == 3) && (*(short *)(iVar4 + 0x10) == 2)) {
        uVar10 = 2;
      }
      if (*(byte *)(iVar4 + 0xc) == 0) {
        bVar9 = *(byte *)(iVar12 + 0x1d);
      }
      else {
        bVar9 = (&co_phy_mask_to_value)[*(byte *)(iVar4 + 0xc)];
      }
      iVar5 = (**(code **)(_r_ip_funcs_p + 0x37c))
                        (param_1,uVar10,(&co_phy_to_rate)[bVar9],*(undefined2 *)(iVar4 + 8),
                         *(code **)(_r_ip_funcs_p + 0x37c));
      if (iVar5 == 0) {
        (**(code **)(_r_ip_funcs_p + 0x684))(iVar4,param_1,7,*(code **)(_r_ip_funcs_p + 0x684));
        goto _L27;
      }
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined1 *)(iVar4 + 0xd),*(undefined1 *)(iVar4 + 0xc),"llc_phy_upd.c",0x2da,
                 *(code **)(_r_plf_funcs_p + 0xc));
    }
    else if (iVar6 == 7) {
      if (*(byte *)(iVar4 + 0xc) != 0) {
        *(undefined *)(iVar12 + 0x1d) = (&co_phy_mask_to_value)[*(byte *)(iVar4 + 0xc)];
      }
      if (*(byte *)(iVar4 + 0xd) != 0) {
        *(undefined *)(iVar12 + 0x1c) = (&co_phy_mask_to_value)[*(byte *)(iVar4 + 0xd)];
      }
    }
    else {
      if (iVar6 != 5) {
        param_3 = 0x1f;
        pcVar11 = *(code **)(_r_plf_funcs_p + 0xc);
        uVar8 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar4,*(code **)(_r_ip_funcs_p + 0x680));
        (*pcVar11)(param_1,uVar8,"llc_phy_upd.c",0x2f3);
        goto _L27;
      }
      uVar3 = *(ushort *)(iVar12 + 0x42);
      *(ushort *)(iVar12 + 0x42) = uVar3 | 0x10;
      if ((uVar3 & 1) == 0) {
        bVar9 = *(byte *)(iVar12 + 0x26) & *(byte *)(iVar4 + 10);
        if ((bVar9 & 4) == 0) {
          bVar9 = ~bVar9 & 1;
        }
        else {
          bVar9 = 3;
          if (*(short *)(iVar12 + 0x24) == 2) {
            bVar9 = 2;
          }
        }
        (**(code **)(_r_ip_funcs_p + 0x3cc))(param_1,bVar9,*(code **)(_r_ip_funcs_p + 0x3cc));
        (**(code **)(_r_ip_funcs_p + 0x684))(iVar4,param_1,6,*(code **)(_r_ip_funcs_p + 0x684));
        llc_ll_phy_rsp_pdu_send
                  (param_1,*(undefined1 *)(iVar12 + 0x26),*(undefined1 *)(iVar12 + 0x27));
        (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,*(code **)(_r_ip_funcs_p + 0x68c));
        goto _L27;
      }
      puVar7 = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x10e,param_1 << 8 | 1,0x14,*(code **)(_r_modules_funcs_p + 200));
      *(undefined1 *)(puVar7 + 1) = 9;
      (**(code **)(_r_ip_funcs_p + 0x684))(param_1,1,*(code **)(_r_ip_funcs_p + 0x684));
      *puVar7 = *(undefined4 *)(_r_ip_funcs_p + 0x64c);
      *(byte *)((int)puVar7 + 10) = *(byte *)(iVar12 + 0x26) & *(byte *)(iVar4 + 10);
      *(byte *)((int)puVar7 + 0xb) = *(byte *)(iVar12 + 0x27) & *(byte *)(iVar4 + 0xb);
      *(undefined2 *)(puVar7 + 4) = *(undefined2 *)(iVar12 + 0x24);
      uVar10 = *(undefined1 *)(iVar4 + 0xf);
      *(undefined1 *)((int)puVar7 + 0xe) = 0;
      *(undefined1 *)((int)puVar7 + 0xf) = uVar10;
      (**(code **)(_r_modules_funcs_p + 0xe0))(puVar7,*(code **)(_r_modules_funcs_p + 0xe0));
    }
  }
  else {
    pcVar11 = *(code **)(_r_ip_funcs_p + 0x3cc);
_L44:
    (*pcVar11)(param_1,4,pcVar11);
  }
  if ((*(ushort *)(iVar12 + 0x42) & 1) == 0) {
    *(ushort *)(iVar12 + 0x42) = *(ushort *)(iVar12 + 0x42) & 0xffef;
    if (*(short *)(iVar4 + 0xc) != 0) {
      (**(code **)(_r_ip_funcs_p + 0x644))
                (param_1,iVar5,*(undefined1 *)(iVar12 + 0x1c),*(undefined1 *)(iVar12 + 0x1d),
                 *(code **)(_r_ip_funcs_p + 0x644));
      (**(code **)(_r_ip_funcs_p + 0x640))(param_1,uVar1,uVar2,*(code **)(_r_ip_funcs_p + 0x640));
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,1,*(code **)(_r_ip_funcs_p + 0x690));
  param_3 = iVar5;
_L27:
                    /* WARNING: Could not recover jumptable at 0x0001013a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x7e8))(0,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x7e8));
  return;
}

