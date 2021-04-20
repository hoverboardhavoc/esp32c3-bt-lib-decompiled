/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_init.o -> lld_init_end_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_init_end_ind_handler_hack(byte *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  byte *pbVar16;
  byte bVar17;
  int iVar18;
  int iVar19;
  ushort uStack_76;
  ushort uStack_74;
  undefined2 uStack_72;
  undefined2 uStack_70;
  undefined2 uStack_6e;
  undefined2 uStack_6c;
  undefined2 uStack_6a;
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
  
  bVar1 = *param_1;
  uVar12 = (uint)bVar1;
  uVar13 = (uint)param_1[0x26];
  bVar17 = param_1[1];
  iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(byte *)(iVar4 + 0xd) <= uVar12) {
    (**(code **)(_r_plf_funcs_p + 0xc))(uVar12,0,"llm_init.c",0x4f,*(code **)(_r_plf_funcs_p + 0xc))
    ;
  }
  iVar4 = uVar12 * 0x44;
  piVar9 = (int *)(*(int *)(_p_llm_env + 8) + iVar4);
  if ((char)piVar9[0x10] == '\x05') {
    iVar14 = *piVar9;
    uVar11 = (ushort)bVar1;
    if (iVar14 == 0) {
      bVar17 = 0;
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
        (*(code *)*_bt_rf_coex_hooks_p)(uVar12,uVar8,0);
      }
      iVar19 = _r_ip_funcs_p;
      iVar5 = _p_llm_env;
      if (bVar17 == 0) {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x40) = 0;
      }
      else {
        memcpy(auStack_68,param_1 + 0x14,4);
        memcpy(auStack_64,param_1 + 0x2c,3);
        uStack_5e = *(undefined2 *)(param_1 + 0x18);
        iVar18 = uVar13 * 0x10 + iVar14;
        uStack_5c = *(undefined2 *)(iVar18 + 0x12);
        uStack_5a = *(undefined2 *)(iVar18 + 0x14);
        uStack_61 = 0;
        bStack_53 = param_1[0x30];
        uStack_60 = 0;
        memcpy(auStack_58,(void *)(iVar5 + 0x1d),5);
        bStack_52 = param_1[0x31];
        uStack_50 = 0;
        uStack_48 = *(undefined4 *)(param_1 + 0x1c);
        uStack_4c = 0;
        bStack_44 = param_1[0x27];
        uStack_43 = 0;
        bStack_42 = param_1[0x34];
        (**(code **)(iVar19 + 0x698))(uVar12,auStack_68,iVar5 + 0x9c,*(code **)(iVar19 + 0x698));
        if (*(char *)(_p_llm_env + 0x22) == '\0') {
          *(undefined1 *)(_p_llm_env + 0x22) = 1;
          (**(code **)(_r_modules_funcs_p + 0xc4))
                    (4,0,(uint)_sdk_cfg_priv_opts * 100,*(code **)(_r_modules_funcs_p + 0xc4));
        }
        iVar5 = _p_llm_env;
        iVar19 = *(int *)(_p_llm_env + 8) + iVar4;
        *(uint *)(iVar19 + 0x14) = (uint)*(ushort *)(param_1 + 0x1a);
        *(uint *)(iVar19 + 0x10) = (uint)*(ushort *)(param_1 + 0x18) << 1;
        uVar10 = (uint)*(ushort *)(iVar18 + 0x16);
        if (uVar10 < 2) {
          uVar10 = 2;
        }
        uVar3 = *(ushort *)(iVar18 + 0x18);
        *(uint *)(iVar19 + 0x18) = uVar10;
        uVar6 = (uint)uVar3;
        if (uVar3 < uVar10) {
          uVar6 = uVar10;
        }
        *(uint *)(iVar19 + 0x1c) = uVar6;
        *(ushort *)(iVar19 + 0x20) = uVar11;
        if (*(char *)(iVar5 + 0xd8) == '\0') {
          *(undefined4 *)(iVar19 + 0x24) = 0;
          *(undefined1 *)(iVar19 + 0x22) = 0;
        }
        else {
          *(undefined4 *)(iVar19 + 0x24) = *(undefined4 *)(_r_ip_funcs_p + 0x5e0);
          *(undefined1 *)(iVar19 + 0x22) = 4;
        }
        iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
        if (*(char *)(iVar5 + 0x15) == '\x01') {
          uVar2 = *(undefined1 *)(iVar19 + 0x20);
          uVar15 = *(uint *)(iVar19 + 0x1c);
          uVar6 = (**(code **)(_r_ip_funcs_p + 0x340))(uVar2,*(code **)(_r_ip_funcs_p + 0x340));
          iVar5 = _r_ip_funcs_p;
          uVar10 = uVar6 / 0x4e2;
          if (uVar6 / 0x4e2 < uVar15) {
            uVar10 = uVar15;
          }
          *(uint *)(iVar19 + 0x1c) = uVar10;
          uVar15 = *(uint *)(iVar19 + 0x18);
          uVar6 = (**(code **)(iVar5 + 0x340))(uVar2,*(code **)(iVar5 + 0x340));
          uVar10 = uVar6 / 0x4e2;
          if (uVar6 / 0x4e2 < uVar15) {
            uVar10 = uVar15;
          }
          *(uint *)(iVar19 + 0x18) = uVar10;
        }
        else {
          iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
          if ((*(char *)(iVar5 + 0x15) == '\x02') &&
             (iVar5 = (**(code **)(_r_ip_funcs_p + 0x344))
                                (*(undefined1 *)(iVar19 + 0x20),&uStack_76,&uStack_74,
                                 *(code **)(_r_ip_funcs_p + 0x344)), iVar5 == 0)) {
            *(uint *)(iVar19 + 0x1c) = (uint)uStack_76;
            *(uint *)(iVar19 + 0x18) = (uint)uStack_74;
          }
        }
        pbVar16 = param_1 + 0xe;
        (**(code **)(_r_ip_funcs_p + 0x6fc))(iVar19 + 0xc,*(code **)(_r_ip_funcs_p + 0x6fc));
        iVar5 = *(int *)(_p_llm_env + 8) + iVar4;
        memcpy((void *)(iVar5 + 4),pbVar16,6);
        bVar1 = param_1[0x20];
        *(undefined1 *)(iVar5 + 0x28) = 0;
        *(byte *)(iVar5 + 0x41) = bVar1 & 1;
        *(undefined1 *)(iVar5 + 0x40) = 9;
        (**(code **)(_r_ip_funcs_p + 0x288))(pbVar16,1,*(code **)(_r_ip_funcs_p + 0x288));
        uVar10 = (**(code **)(_r_ip_funcs_p + 0x4c8))
                           (pbVar16,param_1[0x20],*(code **)(_r_ip_funcs_p + 0x4c8));
        if ((uVar10 < 0xc) && ((*(byte *)(uVar10 * 10 + _p_llm_env + 0x2d) & 2) != 0)) {
          (**(code **)(_r_ip_funcs_p + 0x2c0))
                    (pbVar16,param_1[0x20],*(code **)(_r_ip_funcs_p + 0x2c0));
        }
        (**(code **)(_r_ip_funcs_p + 0x74))(uVar12,*(code **)(_r_ip_funcs_p + 0x74));
        if (_bt_rf_coex_hooks_p != (undefined4 *)0x0) {
          if ((code *)*_bt_rf_coex_hooks_p != (code *)0x0) {
            (*(code *)*_bt_rf_coex_hooks_p)(uVar12,7,1);
          }
          if ((code *)_bt_rf_coex_hooks_p[1] != (code *)0x0) {
            uStack_74 = *(ushort *)(param_1 + 0x18);
            uStack_72 = *(undefined2 *)(iVar18 + 0x12);
            uStack_6c = 0;
            uStack_70 = (undefined2)*(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x1c);
            uStack_6a = 0;
            uStack_6e = 1;
            (*(code *)_bt_rf_coex_hooks_p[1])(uVar12,7,&uStack_74);
          }
        }
      }
    }
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x4e0))(9,*(code **)(_r_ip_funcs_p + 0x4e0));
    if (iVar5 == 0) {
      puVar7 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1104,0,0x3e,0x14);
      memset(puVar7 + 2,0,0x12);
      *puVar7 = 1;
      puVar7[1] = (bVar17 == 0) << 1;
      if (bVar17 != 0) {
        puVar7[4] = 0;
        *(ushort *)(puVar7 + 2) = uVar11;
        if ((param_1[0x20] & 2) == 0) {
          puVar7[5] = param_1[0x20] & 1;
          pbVar16 = param_1 + 0xe;
        }
        else {
          puVar7[5] = 1;
          pbVar16 = param_1 + 8;
        }
        memcpy(puVar7 + 6,pbVar16,6);
        iVar14 = iVar14 + uVar13 * 0x10;
        *(undefined2 *)(puVar7 + 0xc) = *(undefined2 *)(param_1 + 0x18);
        *(undefined2 *)(puVar7 + 0xe) = *(undefined2 *)(iVar14 + 0x12);
        *(undefined2 *)(puVar7 + 0x10) = *(undefined2 *)(iVar14 + 0x14);
        puVar7[0x12] = param_1[0x31];
      }
    }
    else {
      puVar7 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1104,0,0x3e,0x20);
      memset(puVar7 + 2,0,0x1e);
      *puVar7 = 10;
      puVar7[1] = (bVar17 == 0) << 1;
      if (bVar17 != 0) {
        puVar7[4] = 0;
        *(ushort *)(puVar7 + 2) = uVar11;
        memcpy(puVar7 + 6,param_1 + 0xe,6);
        if ((*(byte *)(iVar14 + 1) & 2) == 0) {
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
        iVar14 = iVar14 + uVar13 * 0x10;
        puVar7[5] = param_1[0x20];
        *(undefined2 *)(puVar7 + 0x18) = *(undefined2 *)(param_1 + 0x18);
        *(undefined2 *)(puVar7 + 0x1a) = *(undefined2 *)(iVar14 + 0x12);
        *(undefined2 *)(puVar7 + 0x1c) = *(undefined2 *)(iVar14 + 0x14);
        puVar7[0x1e] = param_1[0x31];
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x8c))(puVar7,*(code **)(_r_ip_funcs_p + 0x8c));
    iVar14 = *(int *)(*(int *)(_p_llm_env + 8) + iVar4);
    if (iVar14 != 0) {
      (**(code **)(_r_modules_funcs_p + 0xd8))(iVar14 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8));
      *(undefined4 *)(iVar4 + *(int *)(_p_llm_env + 8)) = 0;
    }
    if (bVar17 != 0) {
      puVar7 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x1104,0,0x3e,6,*(code **)(_r_modules_funcs_p + 200));
      *puVar7 = 0x14;
      iVar4 = _r_ip_funcs_p;
      bVar17 = param_1[0x34];
      *(ushort *)(puVar7 + 2) = uVar11;
      puVar7[4] = bVar17;
      (**(code **)(iVar4 + 0x8c))(*(code **)(iVar4 + 0x8c));
    }
  }
  else {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar12,*(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)*param_1 * 0x44 + 0x40),
               "llm_init.c",0x13f,*(code **)(_r_plf_funcs_p + 0xc));
  }
  return 0;
}

