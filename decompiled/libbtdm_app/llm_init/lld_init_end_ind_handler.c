/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llm_init.o -> lld_init_end_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_init_end_ind_handler(byte *param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  int *piVar9;
  char cVar10;
  uint uVar11;
  uint uVar12;
  ushort uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  undefined1 uVar18;
  uint uVar19;
  byte *pbVar20;
  int iVar21;
  ushort uStack_76;
  ushort uStack_74;
  undefined2 uStack_72;
  undefined2 uStack_70;
  undefined1 uStack_6e;
  undefined1 uStack_6d;
  undefined1 uStack_6c;
  undefined1 uStack_6b;
  undefined1 uStack_6a;
  undefined1 uStack_69;
  undefined1 auStack_68 [4];
  undefined1 auStack_64 [3];
  undefined1 uStack_61;
  undefined2 uStack_60;
  undefined2 uStack_5e;
  undefined2 uStack_5c;
  undefined2 uStack_5a;
  undefined1 auStack_58 [5];
  byte bStack_53;
  byte bStack_52;
  undefined2 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  byte bStack_44;
  undefined1 uStack_43;
  byte bStack_42;
  
  uVar12 = (uint)param_1[0x26];
  bVar1 = *param_1;
  uVar14 = (uint)bVar1;
  uVar17 = (uint)param_1[1];
  iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(byte *)(iVar4 + 0xd) <= uVar14) {
    (**(code **)(_r_plf_funcs_p + 0xc))(uVar14,0,0x10000,0x2ad,*(code **)(_r_plf_funcs_p + 0xc));
  }
  iVar4 = uVar14 * 0x44;
  piVar9 = (int *)(*(int *)(_p_llm_env + 8) + iVar4);
  if ((char)piVar9[0x10] == '\x05') {
    iVar15 = *piVar9;
    uVar13 = (ushort)bVar1;
    if (iVar15 == 0) {
      uVar17 = 0;
      (**(code **)(_r_ip_funcs_p + 0x4b8))(0x200e,0,*(code **)(_r_ip_funcs_p + 0x4b8));
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x40) = 0;
    }
    else {
      if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
         ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
        uVar8 = 3;
        if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
          uVar8 = 1;
        }
        (*(code *)*_bt_rf_coex_hooks_p)(uVar14,uVar8,0);
      }
      iVar21 = _r_ip_funcs_p;
      iVar5 = _p_llm_env;
      if (uVar17 == 0) {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x40) = 0;
      }
      else {
        memcpy(auStack_68,param_1 + 0x14,4);
        memcpy(auStack_64,param_1 + 0x2c,3);
        uStack_5e = *(undefined2 *)(param_1 + 0x18);
        iVar16 = uVar12 * 0x10 + iVar15;
        uStack_5c = *(undefined2 *)(iVar16 + 0x12);
        uStack_5a = *(undefined2 *)(iVar16 + 0x14);
        uStack_61 = 0;
        uStack_60 = 0;
        bStack_53 = param_1[0x30];
        memcpy(auStack_58,(void *)(iVar5 + 0x1d),5);
        bStack_52 = param_1[0x31];
        uStack_50 = 0;
        uStack_48 = *(undefined4 *)(param_1 + 0x1c);
        uStack_4c = 0;
        bStack_44 = param_1[0x27];
        uStack_43 = 0;
        bStack_42 = param_1[0x34];
        (**(code **)(iVar21 + 0x698))(uVar14,auStack_68,iVar5 + 0x9c,*(code **)(iVar21 + 0x698));
        if (*(char *)(_p_llm_env + 0x22) == '\0') {
          *(undefined1 *)(_p_llm_env + 0x22) = 1;
          (**(code **)(_r_modules_funcs_p + 0xc4))
                    (4,0,(uint)_sdk_cfg_priv_opts * 100,*(code **)(_r_modules_funcs_p + 0xc4));
        }
        iVar5 = _p_llm_env;
        iVar21 = *(int *)(_p_llm_env + 8) + iVar4;
        *(uint *)(iVar21 + 0x14) = (uint)*(ushort *)(param_1 + 0x1a);
        *(uint *)(iVar21 + 0x10) = (uint)*(ushort *)(param_1 + 0x18) << 1;
        uVar11 = (uint)*(ushort *)(iVar16 + 0x16);
        if (uVar11 < 2) {
          uVar11 = 2;
        }
        uVar2 = *(ushort *)(iVar16 + 0x18);
        *(uint *)(iVar21 + 0x18) = uVar11;
        uVar6 = (uint)uVar2;
        if (uVar2 < uVar11) {
          uVar6 = uVar11;
        }
        *(uint *)(iVar21 + 0x1c) = uVar6;
        *(ushort *)(iVar21 + 0x20) = uVar13;
        cVar10 = *(char *)(iVar5 + 0xd8);
        uVar8 = 0;
        if (cVar10 != '\0') {
          uVar8 = *(undefined4 *)(_r_ip_funcs_p + 0x5e0);
          cVar10 = '\x04';
        }
        *(char *)(iVar21 + 0x22) = cVar10;
        iVar5 = _r_plf_funcs_p;
        *(undefined4 *)(iVar21 + 0x24) = uVar8;
        iVar5 = (**(code **)(iVar5 + 0x38))(*(code **)(iVar5 + 0x38));
        if (*(char *)(iVar5 + 0x15) == '\x01') {
          uVar18 = *(undefined1 *)(iVar21 + 0x20);
          uVar19 = *(uint *)(iVar21 + 0x1c);
          uVar6 = (**(code **)(_r_ip_funcs_p + 0x340))(uVar18,*(code **)(_r_ip_funcs_p + 0x340));
          iVar5 = _r_ip_funcs_p;
          uVar11 = uVar6 / 0x4e2;
          if (uVar6 / 0x4e2 < uVar19) {
            uVar11 = uVar19;
          }
          *(uint *)(iVar21 + 0x1c) = uVar11;
          uVar19 = *(uint *)(iVar21 + 0x18);
          uVar6 = (**(code **)(iVar5 + 0x340))(uVar18,*(code **)(iVar5 + 0x340));
          uVar11 = uVar6 / 0x4e2;
          if (uVar6 / 0x4e2 < uVar19) {
            uVar11 = uVar19;
          }
          *(uint *)(iVar21 + 0x18) = uVar11;
        }
        else {
          iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
          if ((*(char *)(iVar5 + 0x15) == '\x02') &&
             (iVar5 = (**(code **)(_r_ip_funcs_p + 0x344))
                                (*(undefined1 *)(iVar21 + 0x20),&uStack_76,&uStack_74,
                                 *(code **)(_r_ip_funcs_p + 0x344)), iVar5 == 0)) {
            *(uint *)(iVar21 + 0x1c) = (uint)uStack_76;
            *(uint *)(iVar21 + 0x18) = (uint)uStack_74;
          }
        }
        pbVar20 = param_1 + 0xe;
        (**(code **)(_r_ip_funcs_p + 0x6fc))(iVar21 + 0xc,*(code **)(_r_ip_funcs_p + 0x6fc));
        iVar5 = *(int *)(_p_llm_env + 8) + iVar4;
        memcpy((void *)(iVar5 + 4),pbVar20,6);
        bVar1 = param_1[0x20];
        *(undefined1 *)(iVar5 + 0x28) = 0;
        *(byte *)(iVar5 + 0x41) = bVar1 & 1;
        *(undefined1 *)(iVar5 + 0x40) = 9;
        (**(code **)(_r_ip_funcs_p + 0x288))(pbVar20,1,*(code **)(_r_ip_funcs_p + 0x288));
        uVar11 = (**(code **)(_r_ip_funcs_p + 0x4c8))
                           (pbVar20,param_1[0x20],*(code **)(_r_ip_funcs_p + 0x4c8));
        if ((uVar11 < 0xc) && ((*(byte *)(uVar11 * 10 + _p_llm_env + 0x2d) & 2) != 0)) {
          (**(code **)(_r_ip_funcs_p + 0x2c0))
                    (pbVar20,param_1[0x20],*(code **)(_r_ip_funcs_p + 0x2c0));
        }
        (**(code **)(_r_ip_funcs_p + 0x74))(uVar14,*(code **)(_r_ip_funcs_p + 0x74));
        if (_bt_rf_coex_hooks_p != (undefined4 *)0x0) {
          if ((code *)*_bt_rf_coex_hooks_p != (code *)0x0) {
            (*(code *)*_bt_rf_coex_hooks_p)(uVar14,7,1);
          }
          if ((code *)_bt_rf_coex_hooks_p[1] != (code *)0x0) {
            uStack_74 = *(ushort *)(param_1 + 0x18);
            uStack_72 = *(undefined2 *)(iVar16 + 0x12);
            uStack_6d = 0;
            uStack_6c = 0;
            uStack_70 = (undefined2)*(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x1c);
            uStack_6b = 0;
            uStack_6a = 0;
            uStack_69 = 0;
            uStack_6e = 1;
            (*(code *)_bt_rf_coex_hooks_p[1])(uVar14,7,&uStack_74);
          }
        }
      }
    }
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x4e0))(9,*(code **)(_r_ip_funcs_p + 0x4e0));
    uVar18 = (undefined1)(((uVar17 ^ 1) & 0x7f) << 1);
    if (iVar5 == 0) {
      puVar7 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1104,0,0x3e,0x14);
      memset(puVar7,0,0x14);
      *puVar7 = 1;
      puVar7[1] = uVar18;
      if (uVar17 != 0) {
        *(ushort *)(puVar7 + 2) = uVar13;
        if ((param_1[0x20] & 2) == 0) {
          puVar7[5] = param_1[0x20] & 1;
          pbVar20 = param_1 + 0xe;
        }
        else {
          puVar7[5] = 1;
          pbVar20 = param_1 + 8;
        }
        memcpy(puVar7 + 6,pbVar20,6);
        *(undefined2 *)(puVar7 + 0xc) = *(undefined2 *)(param_1 + 0x18);
        iVar15 = iVar15 + uVar12 * 0x10;
        *(undefined2 *)(puVar7 + 0xe) = *(undefined2 *)(iVar15 + 0x12);
        *(undefined2 *)(puVar7 + 0x10) = *(undefined2 *)(iVar15 + 0x14);
        puVar7[0x12] = param_1[0x31];
      }
    }
    else {
      puVar7 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1104,0,0x3e,0x20);
      memset(puVar7,0,0x20);
      *puVar7 = 10;
      puVar7[1] = uVar18;
      if (uVar17 != 0) {
        *(ushort *)(puVar7 + 2) = uVar13;
        memcpy(puVar7 + 6,param_1 + 0xe,6);
        if ((*(byte *)(iVar15 + 1) & 2) == 0) {
          memset(puVar7 + 0xc,0,6);
        }
        else {
          memcpy(puVar7 + 0xc,param_1 + 2,6);
        }
        if ((param_1[0x20] & 2) == 0) {
          memset(puVar7 + 0x12,0,6);
        }
        else {
          memcpy(puVar7 + 0x12,param_1 + 8,6);
        }
        puVar7[5] = param_1[0x20];
        *(undefined2 *)(puVar7 + 0x18) = *(undefined2 *)(param_1 + 0x18);
        iVar15 = uVar12 * 0x10 + iVar15;
        uVar3 = *(undefined2 *)(iVar15 + 0x14);
        *(undefined2 *)(puVar7 + 0x1a) = *(undefined2 *)(iVar15 + 0x12);
        *(undefined2 *)(puVar7 + 0x1c) = uVar3;
        puVar7[0x1e] = param_1[0x31];
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x8c))(puVar7,*(code **)(_r_ip_funcs_p + 0x8c));
    iVar15 = *(int *)(*(int *)(_p_llm_env + 8) + iVar4);
    if (iVar15 != 0) {
      (**(code **)(_r_modules_funcs_p + 0xd8))(iVar15 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8));
      *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar4) = 0;
    }
    if (uVar17 != 0) {
      puVar7 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1104,0,0x3e,6,*(code **)(_r_modules_funcs_p + 200));
      *puVar7 = 0x14;
      iVar4 = _r_ip_funcs_p;
      bVar1 = param_1[0x34];
      *(ushort *)(puVar7 + 2) = uVar13;
      puVar7[4] = bVar1;
      (**(code **)(iVar4 + 0x8c))(*(code **)(iVar4 + 0x8c));
    }
  }
  else {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar14,*(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)*param_1 * 0x44 + 0x40),
               0x10000,0x3a2,*(code **)(_r_plf_funcs_p + 0xc));
  }
  return 0;
}

