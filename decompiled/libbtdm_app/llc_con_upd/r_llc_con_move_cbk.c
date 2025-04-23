/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_con_move_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_con_move_cbk(uint param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar8 = param_1 & 0xff;
  iVar6 = uVar8 * 4;
  if (*(int *)(&llc_env + iVar6) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x6ee,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (uVar8 < *(byte *)(iVar2 + 0xd)) {
    iVar2 = *(int *)(&llc_env + iVar6);
    if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
      if (((*(byte *)(iVar2 + 0x45) & 0x10) == 0) && (-1 < (char)*(byte *)(iVar2 + 0x45))) {
        puVar3 = (undefined4 *)
                 (**(code **)(_r_modules_funcs_p + 200))
                           (0x10b,(param_1 & 0xff) << 8 | 1,0x30,
                            *(code **)(_r_modules_funcs_p + 200));
        iVar2 = (**(code **)(_r_ip_funcs_p + 0x4f0))(uVar8,*(code **)(_r_ip_funcs_p + 0x4f0));
        if (*(int *)(&llc_env + iVar6) == 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x6f8,*(code **)(_r_plf_funcs_p + 8));
        }
        if (iVar2 == 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x6f9,*(code **)(_r_plf_funcs_p + 8));
        }
        if (*(int *)(iVar2 + 4) == 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x6fa,*(code **)(_r_plf_funcs_p + 8));
        }
        uVar9 = *(uint *)(iVar2 + 0xc);
        uVar7 = *(uint *)(iVar2 + 0x10);
        if ((*(ushort *)(*(int *)(&llc_env + iVar6) + 0x42) & 1) == 0) {
          if ((uVar9 < 4) || (uVar7 < uVar9)) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"llc_con_upd.c",0x701,*(code **)(_r_plf_funcs_p + 8));
          }
          uVar9 = uVar9 - 3;
          uVar7 = uVar7 - 3;
        }
        *(undefined1 *)(puVar3 + 1) = 5;
        (**(code **)(_r_ip_funcs_p + 0x684))(puVar3,uVar8,0,*(code **)(_r_ip_funcs_p + 0x684));
        uVar5 = *(undefined4 *)(_r_ip_funcs_p + 0x5f8);
        *(short *)((int)puVar3 + 0x12) = (short)uVar7;
        *puVar3 = uVar5;
        iVar2 = *(int *)(&llc_env + iVar6);
        *(short *)(puVar3 + 4) = (short)uVar9;
        uVar1 = *(undefined2 *)(iVar2 + 0xe);
        *(undefined2 *)((int)puVar3 + 10) = uVar1;
        *(undefined2 *)(puVar3 + 2) = uVar1;
        *(undefined2 *)(puVar3 + 3) = *(undefined2 *)(iVar2 + 0x10);
        *(undefined2 *)((int)puVar3 + 0xe) = *(undefined2 *)(iVar2 + 0x12);
        bVar4 = 0;
        if ((*(ushort *)(iVar2 + 0x42) & 1) != 0) {
          iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
          bVar4 = 0;
          if ((uVar8 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + iVar6), iVar2 != 0))
          {
            bVar4 = (byte)((int)(uint)*(byte *)(iVar2 + 0x30) >> 1) & 1;
          }
          bVar4 = bVar4 ^ 1;
        }
        *(byte *)(puVar3 + 0xb) = bVar4;
        *(undefined2 *)((int)puVar3 + 0x16) = 0xffff;
        iVar2 = _r_modules_funcs_p;
        *(undefined1 *)((int)puVar3 + 0x2d) = 0;
        *(undefined1 *)((int)puVar3 + 0x2e) = 0;
        (**(code **)(iVar2 + 0xe0))(puVar3,*(code **)(iVar2 + 0xe0));
        *(byte *)(*(int *)(&llc_env + iVar6) + 0x45) =
             *(byte *)(*(int *)(&llc_env + iVar6) + 0x45) | 0x80;
      }
    }
  }
  return;
}

