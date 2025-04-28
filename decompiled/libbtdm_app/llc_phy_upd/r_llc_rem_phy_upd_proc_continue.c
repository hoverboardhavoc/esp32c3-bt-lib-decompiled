/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  undefined4 *puVar6;
  undefined4 uVar7;
  byte bVar8;
  undefined1 uVar9;
  int iVar10;
  code *pcVar11;
  
  iVar10 = *(int *)(&llc_env + param_1 * 4);
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x674))(1,*(code **)(_r_ip_funcs_p + 0x674));
  uVar1 = *(undefined1 *)(iVar10 + 0x1c);
  uVar2 = *(undefined1 *)(iVar10 + 0x1d);
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x7e8))
                    (1,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x7e8));
  if (iVar5 != 0) {
    return;
  }
  if (param_3 == 0) {
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar4,*(code **)(_r_ip_funcs_p + 0x680));
    if (iVar5 != param_2) {
      pcVar11 = *(code **)(_r_plf_funcs_p + 0x10);
      (**(code **)(_r_ip_funcs_p + 0x680))(iVar4,*(code **)(_r_ip_funcs_p + 0x680));
      (*pcVar11)(param_2,"llc_phy_upd.c",0x26e);
      goto _L12;
    }
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar4,*(code **)(_r_ip_funcs_p + 0x680));
    if (iVar5 == 6) {
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,0,*(code **)(_r_ip_funcs_p + 0x68c));
      if (*(short *)(iVar4 + 0xc) == 0) goto _L39;
      if (*(byte *)(iVar4 + 0xd) == 0) {
        bVar8 = *(byte *)(iVar10 + 0x1c);
      }
      else {
        bVar8 = (&co_phy_mask_to_value)[*(byte *)(iVar4 + 0xd)];
      }
      uVar9 = (&co_phy_to_rate)[bVar8];
      if ((bVar8 == 3) && (*(short *)(iVar4 + 0x10) == 2)) {
        uVar9 = 2;
      }
      if (*(byte *)(iVar4 + 0xc) == 0) {
        bVar8 = *(byte *)(iVar10 + 0x1d);
      }
      else {
        bVar8 = (&co_phy_mask_to_value)[*(byte *)(iVar4 + 0xc)];
      }
      param_3 = (**(code **)(_r_ip_funcs_p + 0x37c))
                          (param_1,uVar9,(&co_phy_to_rate)[bVar8],*(undefined2 *)(iVar4 + 8),
                           *(code **)(_r_ip_funcs_p + 0x37c));
      if (param_3 == 0) {
        (**(code **)(_r_ip_funcs_p + 0x684))(iVar4,param_1,7,*(code **)(_r_ip_funcs_p + 0x684));
        goto _L12;
      }
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined1 *)(iVar4 + 0xd),*(undefined1 *)(iVar4 + 0xc),"llc_phy_upd.c",0x2da,
                 *(code **)(_r_plf_funcs_p + 0xc));
    }
    else if (iVar5 == 7) {
      if (*(byte *)(iVar4 + 0xc) != 0) {
        *(undefined *)(iVar10 + 0x1d) = (&co_phy_mask_to_value)[*(byte *)(iVar4 + 0xc)];
      }
      if (*(byte *)(iVar4 + 0xd) == 0) {
        param_3 = 0;
      }
      else {
        *(undefined *)(iVar10 + 0x1c) = (&co_phy_mask_to_value)[*(byte *)(iVar4 + 0xd)];
      }
    }
    else {
      if (iVar5 != 5) {
        param_3 = 0x1f;
        pcVar11 = *(code **)(_r_plf_funcs_p + 0xc);
        uVar7 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar4,*(code **)(_r_ip_funcs_p + 0x680));
        (*pcVar11)(param_1,uVar7,"llc_phy_upd.c",0x2f3);
        goto _L12;
      }
      uVar3 = *(ushort *)(iVar10 + 0x42);
      *(ushort *)(iVar10 + 0x42) = uVar3 | 0x10;
      if ((uVar3 & 1) == 0) {
        bVar8 = *(byte *)(iVar10 + 0x26) & *(byte *)(iVar4 + 10);
        if ((bVar8 & 4) == 0) {
          bVar8 = ~bVar8 & 1;
        }
        else {
          bVar8 = 2;
          if (*(short *)(iVar10 + 0x24) != 2) {
            bVar8 = 3;
          }
        }
        (**(code **)(_r_ip_funcs_p + 0x3cc))(param_1,bVar8,*(code **)(_r_ip_funcs_p + 0x3cc));
        (**(code **)(_r_ip_funcs_p + 0x684))(iVar4,param_1,6,*(code **)(_r_ip_funcs_p + 0x684));
        llc_ll_phy_rsp_pdu_send
                  (param_1,*(undefined1 *)(iVar10 + 0x26),*(undefined1 *)(iVar10 + 0x27));
        (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,1,*(code **)(_r_ip_funcs_p + 0x68c));
        goto _L12;
      }
      puVar6 = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x10e,param_1 << 8 | 1,0x14,*(code **)(_r_modules_funcs_p + 200));
      *(undefined1 *)(puVar6 + 1) = 9;
      (**(code **)(_r_ip_funcs_p + 0x684))(param_1,1,*(code **)(_r_ip_funcs_p + 0x684));
      *puVar6 = *(undefined4 *)(_r_ip_funcs_p + 0x64c);
      *(byte *)((int)puVar6 + 10) = *(byte *)(iVar10 + 0x26) & *(byte *)(iVar4 + 10);
      *(byte *)((int)puVar6 + 0xb) = *(byte *)(iVar10 + 0x27) & *(byte *)(iVar4 + 0xb);
      *(undefined2 *)(puVar6 + 4) = *(undefined2 *)(iVar10 + 0x24);
      uVar9 = *(undefined1 *)(iVar4 + 0xf);
      *(undefined1 *)((int)puVar6 + 0xe) = 0;
      *(undefined1 *)((int)puVar6 + 0xf) = uVar9;
      (**(code **)(_r_modules_funcs_p + 0xe0))(puVar6,*(code **)(_r_modules_funcs_p + 0xe0));
    }
  }
  else {
_L39:
    (**(code **)(_r_ip_funcs_p + 0x3cc))(param_1,4,*(code **)(_r_ip_funcs_p + 0x3cc));
  }
  iVar5 = _r_ip_funcs_p;
  if (((*(ushort *)(iVar10 + 0x42) & 1) == 0) &&
     (*(ushort *)(iVar10 + 0x42) = *(ushort *)(iVar10 + 0x42) & 0xffef, *(short *)(iVar4 + 0xc) != 0
     )) {
    (**(code **)(iVar5 + 0x644))
              (param_1,param_3,*(undefined1 *)(iVar10 + 0x1c),*(undefined1 *)(iVar10 + 0x1d),
               *(code **)(iVar5 + 0x644));
    (**(code **)(_r_ip_funcs_p + 0x640))(param_1,uVar1,uVar2,*(code **)(_r_ip_funcs_p + 0x640));
  }
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,1,*(code **)(_r_ip_funcs_p + 0x690));
_L12:
                    /* WARNING: Could not recover jumptable at 0x0001013a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x7e8))(0,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x7e8));
  return;
}

